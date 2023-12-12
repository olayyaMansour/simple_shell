#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument value
 * calls onSession_start from shellcore.c
 * Return: Always (SUCCESS)
 */
int main(int argc, char **argv)
{
	onSession_start(argc, (void *)argv[0]);
	return (0);
}
