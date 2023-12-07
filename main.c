#include "core.h"
#include <stdio.h>

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument value
 * calls onSession_start from shellCore.c
 * Return: Always (SUCCESS)
 */
int main(int argc, char **argv)
{
  onSession_start(argc, (void *)argv[0]);
  
	return (0);
}
