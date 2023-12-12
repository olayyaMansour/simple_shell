#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

#define BUFFER_SIZE 1024

void _puts(const char *message);
void displayPrompt(void);
char *readLine(void);
char **splitLine(char *line);
int execute(char **args);
void executeCommand(char **args);
int isExitCommand(char **args);
int isEnvCommand(char **args);
void executeEnv(void);

int isatty(int fd);

<<<<<<< HEAD
=======
char *custom_getline(void);
void executeExit(char** args);
>>>>>>> OM

#endif

