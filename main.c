#include "core.h"
#include <stdio.h>
/**
 * main - Entry point
 * Return: Always (SUCCESS)
 */
int main(int argc, char **argv)
{
	onSession_start(argc, (void *)argv[0]);
	return (0);
}
