#ifndef MAIN_H
#define MAIN_H

#include <stddef.h> // bcs I used size_t
#include <unistd.h> // bcs I used write()
#include <stdlib.h> // bcs I used exit()
#include <sys/types.h> // bcs I used fork()
#include <sys/wait.h> // bcs I used wait()
#include <stdio.h> // bcs I used perror()
#include <string.h> // bcs I used strlen()


#define BUFFER_SIZE 1024 // defining max line length

void _puts(const char *message);
void displayPrompt(void);
char *readLine(void);
char **splitLine(char *line);
int execute(char **args);

#endif

