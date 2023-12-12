#ifndef PATH_LIB
#define PATH_LIB

#include "MemoHandlers.h"
#include "dataHandlers.h"
#include "strLib.h"
#include <sys/stat.h>

#define ST_STAT struct stat

bool FwdSlashContainer(const char *);

bool isValidPath(const char *);

char *envHandler(char *, char *, char *);

char *pathHandler(char *, char *, char *);

void _perror(char *, char *, short, const char *);

void builtInHandler(char **Cmd, short log);

void pEnv(char **Cmd, short log);

#endif /* PATH_LIB */
