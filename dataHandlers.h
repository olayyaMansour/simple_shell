#ifndef HANDLERS_H
#define HANDLERS_H

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "MemoHandlers.h"

extern char **environ;

char *ReadData(const char *);
bool executeCommands(char **, char *, short);
char **strParsing(char *, char *, char *, char **);

#endif /* HANDLERS_H */
