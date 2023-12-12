#include "pathLib.h"
/**
 * isValidPath - checks if a path is valid
 * @path: path to check
 * Return:
 * true if path is valid or false otherwise
 */

bool isValidPath(const char *path)
{
	ST_STAT st;

	return (stat((char *)path, &st) == false);
}
