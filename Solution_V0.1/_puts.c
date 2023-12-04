#include "main.h"

/**
 * _puts - prints a string to stdout
 * @message: string to print
 *
 * Return: void
 */

void _puts(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}



