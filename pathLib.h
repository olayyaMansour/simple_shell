#ifndef PATH_LIB
#define PATH_LIB

#include "MemoHandlers.h"
#include "dataHandlers.h"
#include "strLib.h"
#include <sys/stat.h>

#define ST_STAT struct stat

bool FwdSlashContainer(const char *);

bool isValidPath(char *);

char **envHandler(char *, char *, char *);

#endif /* PATH_LIB */
