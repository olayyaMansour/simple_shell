#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>


#define BUFFER_SIZE 1024

void _puts(const char *message);
void displayPrompt(void);
char *readLine(void);
char **splitLine(char *line);
int execute(char **args);

#endif

