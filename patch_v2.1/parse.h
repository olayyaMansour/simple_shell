#ifndef PARSE_H
#define PARSE_H
#include <stddef.h>
#include "MemoHandlers.h"
#include "strLib.h"

#define DELIMITER " \n\t"

char **reshapeArr(char **, int *, short);
char **parseToken(char **, int *, int  *, char *);
char **_INIT_TOKENS(char **, int *);
#endif /* PARSE_H */
