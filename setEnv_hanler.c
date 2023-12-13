#include "core.h"
#include "MemoHandlers.h"
#include "dataHandlers.h"

void setEnvHandler(char **Cmd, short log)
{
  if (Cmd[1] != NULL && Cmd[2] != NULL && Cmd[3] == NULL)
  {
    if (setenv(Cmd[1], Cmd[2], 1) != 0)
    {
      perror("setenv");
      log = 1;
    }
  }
  else
  {
    fprintf(stderr, "setenv: Incorrect syntax\n");
    log = 1;
  }

  _freeArr(Cmd);
  printf("success: %d\n", log);
}

void unsetEnvHandler(char **Cmd, short log)
{
  if (Cmd[1] != NULL && Cmd[2] == NULL)
  {
    if (unsetenv(Cmd[1]) != 0)
    {
      perror("unsetenv");
      log = 1;
    }
  }
  else
  {
    fprintf(stderr, "unsetenv: Incorrect syntax\n");
    log = 1;
  }

  _freeArr(Cmd);
  printf("success: %d\n", log);
}

