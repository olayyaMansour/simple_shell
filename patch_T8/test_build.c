#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>

#define ST_STAT struct st
#define DELIMITER " \t\n"
extern char **environ;

void replaceVariables(char **Cmd, int exitStatus);
char *ReadData(const char *Message);

char **strParsing(char *data, char *dataContainer, char *token, char **Cmd);

char *envHandler(char *envName, char *envValue, char *envKey);

char *pathHandler(char *Cmd, char *Path, char *originalPath);

bool executeCommands(char **Cmd, char *str, short Counter);

void exeChildProcess(char *cmdPath, char **Cmd);

short waitForChildProc(pid_t procId, char *cmdPath, char **Cmd);

void onSession_start(int argc, char *str);

void onTrigger(char *str, short Counter);

void onExit(char **Cmd, short log);

void _freeArr(char **Arr);

void _freeMemo(char *firstStr, char *secondStr);

char *_strChr(char *str, short chr);

short _strCompare(char *str1, char *str2);

char *_strDuplicate(char *str);

char *_strCpNConcat(char *firstStr, char *secondStr);

char **_INIT_TOKENS(char **arrToken, int *limiter);

bool isValidPath(const char *path);

bool FwdSlashContainer(const char *str);

char **reshapeArr(char **arr, int *limiter, short resize);

char **parseToken(char **arr, int *counter, int *limiter, char *token);

void _perror(char *Name, char *Cmd, short posIndex, const char *Msg);

bool _isNewlineOrSpace(char c);

bool CheckNewlineOrSpace(const char *str);

void newlineOrSpaceHandler(char **str);

void builtInHandler(char **Cmd, short log);

void pEnv(char **Cmd, short log);

char *handleNewDirec(char **, char *, char *, short);

char *handleOldDirec();

void changeDirecHandler(char **Cmd, char *direc, char *str, short Counter);

int main(int argc, char **argv)
{
  onSession_start(argc, (void *)argv[0]);
  return (0);
}

char *ReadData(const char *Message) {
    char *Cmd = NULL;
    size_t sizeOfBuffer = 0;
    ssize_t Length;
    int log = 0;

    if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, Message, strlen(Message));
    }

    Length = getline(&Cmd, &sizeOfBuffer, stdin);

    if (Length > 0) {
        char *commentPos = strchr(Cmd, '#');
        if (commentPos != NULL) {
            *commentPos = '\0';
            Length = commentPos - Cmd;
        }

        if (Cmd[Length - 1] == '\n') {
            Cmd[Length - 1] = '\0';
        }
    } else if (Length == -1) {
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "\n", 1);
        }
        free(Cmd);
        onExit(NULL, log);
    }

    return Cmd;
}


char **strParsing(char *data, char *dataContainer, char *token, char **Cmd)
{
  int i = 0, limiter = 1;

  if (!data)
    return (NULL);

  dataContainer = _strDuplicate(data);
  token = strtok(dataContainer, DELIMITER);

  Cmd = _INIT_TOKENS(&token, &limiter);

  if (Cmd)
  {
    while (token != NULL)
    {
      Cmd = parseToken(Cmd, &i, &limiter, token);
      if (!Cmd)
      {
        _freeMemo(dataContainer, data);
        return (NULL);
      }
      token = strtok(NULL, DELIMITER);
    }
  }
  else
  {
    _freeMemo(dataContainer, data);
    return (NULL);
  }

  Cmd[i] = NULL;
  _freeMemo(dataContainer, data);

  return (Cmd);
}

char *envHandler(char *envName, char *envValue, char *envKey)
{
  char *Temp = NULL;
  char **envPtr = environ;

  while (*envPtr != NULL)
  {
    Temp = _strDuplicate(*environ);
    envKey = strtok(Temp, "=");

    if (!(_strCompare(envKey, envName) && envKey))
    {
      envValue = _strDuplicate(strtok(NULL, "\n"));
      _freeMemo(Temp, NULL);
      return (envValue);
    }

    _freeMemo(Temp, NULL);
    environ++;
  }

  return (NULL);
}

char *pathHandler(char *Cmd, char *Path, char *originalPath)
{
  char *envValue = NULL;
  (void)Path;

  envValue = envHandler("PATH", NULL, NULL);

  if (!envValue)
    return (NULL);

  if (FwdSlashContainer(Cmd))
  {
    if (isValidPath(Cmd))
    {
      _freeMemo(envValue, NULL);
      return (_strDuplicate(Cmd));
    }
    return (NULL);
  }
  else
  {
    char *Direc = strtok(envValue, ":");

    while (Direc != NULL)
    {
      originalPath = _strCpNConcat(Direc, Cmd);
      if (isValidPath(originalPath))
      {
        _freeMemo(envValue, NULL);
        return (originalPath);
      }
      _freeMemo(originalPath, NULL);
      Direc = strtok(NULL, ":");
    }
  }

  _freeMemo(envValue, NULL);
  return (NULL);
}

bool executeCommands(char **Cmd, char *str, short Counter)
{
  pid_t procId;
  char *cmdPath = NULL;

  cmdPath = (char *)pathHandler(Cmd[0], NULL, NULL);

  if (!(cmdPath))
  {
    _perror(str, Cmd[0], Counter, ": Not found\n");
    _freeArr(Cmd);
    return (true);
  }

  procId = fork();

  if (procId == -1)
  {
    perror("Err! Couldn't fork");
    _freeArr(Cmd);
    return (true);
  }
  else if (procId == 0)
  {
    exeChildProcess(cmdPath, Cmd);
  }
  else
  {
    int exitStatus = waitForChildProc(procId, cmdPath, Cmd);

    _freeMemo(cmdPath, NULL), _freeArr(Cmd);
    return (exitStatus != false ? (false) : (true));
  }
  return (false);
}

void exeChildProcess(char *cmdPath, char **Cmd)
{
  if (execve(cmdPath, Cmd, environ) == -1)
  {
    _freeMemo(cmdPath, NULL);
    _freeArr(Cmd);
  }
}

short waitForChildProc(pid_t procId, char *cmdPath, char **Cmd)
{
  pid_t waitprocId;
  int exitStatus = 0;

  do
  {
    waitprocId = waitpid(procId, &exitStatus, 0);
    if (waitprocId == -1)
    {
      perror("Err! Couldn't wait for child process termination");
      _freeMemo(cmdPath, NULL);
      _freeArr(Cmd);
      return (true);
    }
  } while (waitprocId == 0);

  return (exitStatus);
}

void onSession_start(int argc, char *str)
{
  short Counter = 0;
  (void)argc;

  while (true)
  {
    onTrigger(str, (Counter += 1));
  }
}

void onTrigger(char *str, short Counter)
{
  char *userInput = ReadData("$ ");
  char **Cmd = NULL;
  short log = 0;

  if (userInput == NULL)
    return;

  newlineOrSpaceHandler(&userInput);

  Cmd = strParsing(userInput, NULL, NULL, NULL);
  if (Cmd && Cmd[0])
  {


    char exitFunc = _strCompare(Cmd[0], "exit");
    char envFunc = _strCompare(Cmd[0], "env");
    char cdFunc = _strCompare(Cmd[0], "cd");
replaceVariables(Cmd, log);
    if (exitFunc == false || envFunc == false)
    {
      builtInHandler(Cmd, log);
    }
    else if (cdFunc == false)
    {
      changeDirecHandler(Cmd, Cmd[1], str, Counter);
      _freeArr(Cmd);
    }
    else
    {
      log = executeCommands(Cmd, str, Counter);
    }
  }
}

void onExit(char **Cmd, short log)
{
  (void)Cmd;
  exit(log);
}

void _freeArr(char **Arr)
{
  if (Arr)
  {
    short i;

    for (i = 0; Arr[i] != NULL; i++)
      free(Arr[i]);

    free(Arr);
  }
}

void _freeMemo(char *firstStr, char *secondStr)
{
  free(firstStr);
  free(secondStr);
}

char *_strChr(char *str, short chr)
{
  while (*str != '\0')
  {
    if (*str == chr)
      return ((char *)str);
    str++;
  }

  return (NULL);
}

short _strCompare(char *str1, char *str2)
{
  while (*str1 != '\0' && *str2 != '\0')
  {
    if (*str1 != *str2)
    {
      return ((short)(*str1 - *str2));
    }
    str1++, str2++;
  }
  return ((short)(*str1 - *str2));
}

char *_strDuplicate(char *str)
{
  char *CopiedStr;

  if (str == NULL)
  {
    return (NULL);
  }
  else
  {
    unsigned short i = 0, Length = (strlen(str));

    CopiedStr = (char *)malloc(Length + 1);

    if (CopiedStr == NULL)
      return (NULL);

    for (i = 0; i <= (Length - 1); i++)
      CopiedStr[i] = str[i];

    CopiedStr[Length] = '\0';
  }

  return (CopiedStr);
}

char *_strCpNConcat(char *firstStr, char *secondStr)
{
  char *newStrArr = NULL;
  short firstStrLength = strlen(firstStr) + 1;
  short secondStrLength = strlen(secondStr) + 1;
  short i = 0, j = 0;

  if (firstStr == NULL || secondStr == NULL)
    return (NULL);

  newStrArr = (char *)malloc(firstStrLength + secondStrLength);

  if (newStrArr == NULL)
    return (NULL);

  for (i = 0; i < (firstStrLength - 1); i++)
    newStrArr[i] = firstStr[i];

  newStrArr[i++] = '/';

  while (j < (secondStrLength - 1))
    newStrArr[i++] = secondStr[j++];

  newStrArr[i] = '\0';
  return (newStrArr);
}

char **_INIT_TOKENS(char **arrToken, int *limiter)
{
  arrToken = (char **)malloc(sizeof(char *) * (*limiter));
  return (arrToken);
}

bool isValidPath(const char *path)
{
  struct stat st;

  return (stat((char *)path, &st) == false);
}

bool FwdSlashContainer(const char *str)
{
  return (_strChr((char *)str, 47) != NULL);
}

char **reshapeArr(char **arr, int *limiter, short resize)
{
  char **newArr = NULL;
  short i = 0;

  newArr = (char **)malloc(sizeof(char *) * resize);

  if (newArr != NULL)
  {
    for (i = 0; i < *limiter; i++)
      newArr[i] = arr[i];
  }
  else
  {
    _freeArr(arr);
    return (NULL);
  }

  free(arr);
  *limiter = resize;
  return (newArr);
}

char **parseToken(char **arr, int *counter, int *limiter, char *token)
{
  if (*counter == (*limiter - 1))
  {
    arr = reshapeArr(arr, limiter, (*limiter) * 2);
    if (!arr)
      return (NULL);
  }

  arr[*counter] = _strDuplicate(token);
  (*counter)++;

  return (arr);
}

void _perror(char *Name, char *Cmd, short posIndex, const char *Msg)
{
  char pos[99];
  const char *str = ": ";
  int tempIndex = posIndex, i = 0;
  unsigned short count = 0, Length = strlen(str);

  while (tempIndex != 0)
  {
    tempIndex /= 10;
    count++;
  }

  if (count == 0)
  {
    pos[0] = '0';
    count = 1;
  }

  for (i = count - 1; i >= 0; i--)
  {
    pos[i] = '0' + posIndex % 10;
    posIndex /= 10;
  }

  write(STDERR_FILENO, Name, strlen(Name));
  write(STDERR_FILENO, ": ", sizeof(Length));
  write(STDERR_FILENO, pos, count);
  write(STDERR_FILENO, ": ", sizeof(Length));
  write(STDERR_FILENO, Cmd, strlen(Cmd));
  write(STDERR_FILENO, Msg, strlen(Msg));
}

bool _isNewlineOrSpace(char c)
{
  return (c == ' ' || c == '\n');
}

bool CheckNewlineOrSpace(const char *str)
{
  size_t i = 0;

  for (i = 0; i < (strlen(str)); i++)
  {
    if (!_isNewlineOrSpace(str[i]))
      return (false);
  }

  return (true);
}

void newlineOrSpaceHandler(char **str)
{
  if (CheckNewlineOrSpace(*str))
  {
    free(*str);
    *str = NULL;
  }
}

void builtInHandler(char **Cmd, short log)
{
  if (Cmd == NULL || Cmd[0] == NULL)
    return;

  if (_strCompare(Cmd[0], "exit") == 0)
  /*add a check for the presence of a second argument after exit, if it is there, then exit with the status of this argument, otherwise exit with the status of the last command*/
  {
    if (Cmd[1] != NULL)
    {
      int exitStatus = atoi(Cmd[1]);
      _freeArr(Cmd);
      exit(exitStatus);
    }
    else
    {
      _freeArr(Cmd);
      exit(log);
    }
  }
  else if (_strCompare(Cmd[0], "env") == 0)
  {
    _freeArr(Cmd);
    pEnv(Cmd, log);
  }
}

void pEnv(char **Cmd, short log)
{
  short i = 0;
  (void)log;
  (void)Cmd;

  for (i = 0; environ[i]; i++)
  {
    write(STDOUT_FILENO, environ[i], strlen(environ[i]));
    write(STDOUT_FILENO, "\n", 1);
  }
}

void changeDirecHandler(char **Cmd, char *direc, char *str, short Counter)
{
  char *Err = NULL;
  char *newDirec = handleNewDirec(Cmd, direc, str, Counter);
  char *oldDirec = handleOldDirec();

  if (newDirec == NULL)
  {
    Err = " : no such file or directory\n";
    _perror(str, Cmd[0], Counter, Err);
    exit(99);
  }

  if (oldDirec != NULL)
  {
    if (!chdir(newDirec))
    {
      setenv("OLDPWD", oldDirec, 1);
      setenv("PWD", newDirec, 1);
    }
    else
    {
      Err = " : couldn't change directory\n";
      _perror(str, Cmd[0], Counter, Err);
      _freeMemo(newDirec, oldDirec);
      return;
    }
  }
  else
  {
    Err = " : Err! couldn't get this directory\n";
    _perror(str, Cmd[0], Counter, Err);
    _freeMemo(newDirec, NULL);
    exit(99);
  }

  _freeMemo(newDirec, oldDirec);
}

char *handleNewDirec(char **Cmd, char *direc, char *str, short Counter)
{
  char checker = (direc == NULL ? 0 : _strCompare(direc, "-"));
  char *newDirec = NULL;
  const char *Err = NULL;

  switch (checker)
  {
  case 0:
    newDirec = envHandler("HOME", NULL, NULL);
    break;
  case 1:
    newDirec = envHandler("OLDPWD", NULL, NULL);
    break;
  default:
    newDirec = _strDuplicate(direc);

    if (newDirec == NULL)
    {
      Err = " : No such file or directory\n";
      _perror(str, Cmd[0], Counter, Err);
      return (NULL);
    }
  }

  return (newDirec);
}

char *handleOldDirec()
{
  return (getcwd(NULL, 0));
}
void replaceVariables(char **Cmd, int exitStatus) {
    int i;
    char exitStatusStr[12];
    char pidStr[12];

	for (i = 0; Cmd[i] != NULL; i++) {
        if (Cmd[i][0] == '$') {
            if (strcmp(Cmd[i], "$?") == 0) {
                
               
                snprintf(exitStatusStr, sizeof(exitStatusStr), "%d", exitStatus);
                free(Cmd[i]);
                Cmd[i] = _strDuplicate(exitStatusStr);
            } else if (strcmp(Cmd[i], "$$") == 0) {
                
                
                snprintf(pidStr, sizeof(pidStr), "%d", getpid());
                free(Cmd[i]);
                Cmd[i] = _strDuplicate(pidStr);
            }
	    else {
		    char *envValue = getenv(Cmd[i] + 1);  
                if (envValue != NULL) {
                    free(Cmd[i]);
                    Cmd[i] = _strDuplicate(envValue); }
        }
    }
}
}
