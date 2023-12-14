# Team Project
* Simple Shell

# Used Functions

## Data reader:
* ReadData - reads user input from terminal
* @Message: string to be outputed
* Return: entered user command

## Shell Core(3 system loop functions):
* onSession_start - starts a session
* calls onTrigger() func in an infinte loop

* onTrigger - trigger the user input to read from
* uses custom built string comparison to check
* for a specified word(string)
* calls strParsing()
* calls onExit() if condition is met
* calls builInHandler() if condition is met
* calls executeCommands() if condition is met
* calls newlineOrSpaceHandler() if condition is met
* calls changeDirecHandler() if condition is met

* onExit - exits the session

## Commands Exec:
* executeCommands - execute a command using fork and execve
* exeChildProcess - executes child process using execve
* waitForChildProc - waits for child process to terminate
* exit status of child process

## String Parsing:
* _INIT_TOKENS - init array of tokens with given limiter
* reshapeArr - resize/reshape array to new size
* parseToken - adds tokens to arr(array of tokens), reshape if necessary
* strParsing - tokenizes a string into an arr of strings

## Path Handler:
* FwdSlashContainer - checks if a string contains a forward slash '/' char
* isValidPath - checks if a path is valid
* pathHandler - finds path of the specified command to be executed

## Environment Handler:
* envHandler - retrieves value of an environment var
* pEnv - handles the env variables

## Space or Newline Handler:
* newlineOrSpaceHandler - frees if spaces followed by newline or just newline
* _isNewlineOrSpace - returns either a space or newline
* CheckNewlineOrSpace - checks if a string has a newline or space

## Memory Handlers:
* _freeArr - free memory for an array
* _freeMemo - frees strings

## Helper Functions:
* _strCompare - compares each char of 2 strings
* _strDuplicate - allocate memory and returns a ptr to a copied string
* _strCpNConcat - copies string 1 and 2 into an array then concatenate
* _strChr - finds the first occurence of a char in a given string
* _perror - prints a similar error like shell
* builtInHandler - compares and checks userInput command


# Unused Functions

## Change Directory Handler (cd Command):
* changeDirecHandler - changes from old->new dir and updates envVar
* calls handleNewDirec() and handleOldDirec() functions
* checks if new directory is NULL or not
* checks if old directory(current) is NULL or not
* updates envVars PWD & OLDPWD when changing directory
* frees memory on failure
* changes the working directory base on the user input.

* handleNewDirec - handles new direc based on userInput
* gets back a string(new directory) or NULL on failure


* handleOldDirec - handles old(current) working directory
* gets back a string(new directory) or NULL on failure
