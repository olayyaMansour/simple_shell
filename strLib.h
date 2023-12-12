#ifndef ADDONS_H
#define ADDONS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

short _strCompare(char *, char *);
char *_strDuplicate(char *);
char *_strCpNConcat(char *, char *);
char *_strChr(char *, short);
bool CheckNewlineOrSpace(const char *);
bool _isNewlineOrSpace(char);
void newlineOrSpaceHandler(char **);

#endif /* ADDONS_H */
