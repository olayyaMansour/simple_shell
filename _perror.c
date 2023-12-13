#include "dataHandlers.h"
#include "strLib.h"
/**
 * _perror - prints a similar error like shell
 * @Name: custom shell name
 * @Cmd: wrong entered command
 * @posIndex: error position number(calculted using a counter)
 * @Msg: error message
 *
 * function prints an error message to standard error output
 * format is: "<Name>: <posIndex>: <Cmd>: <Msg>\n"
 */
void _perror(char *Name, char *Cmd, short posIndex, const char *Msg)
{
	char pos[99];
	const char *str = ": ";
	int tempIndex = posIndex, i = 0;
	unsigned short count = 0, Length = strlen(str);

	while (tempIndex != 0)
	{
	tempIndex /= 10;
	count++;
	}

	if (count == 0)
	{
	pos[0] = '0';
	count = 1;
	}


	for (i = count - 1; i >= 0; i--)
	{
	pos[i] = '0' + posIndex % 10;
	posIndex /= 10;
	}

	write(STDERR_FILENO, Name, strlen(Name));
	write(STDERR_FILENO, ": ", sizeof(Length));
	write(STDERR_FILENO, pos, count);
	write(STDERR_FILENO, ": ", sizeof(Length));
	write(STDERR_FILENO, Cmd, strlen(Cmd));
	write(STDERR_FILENO, Msg, strlen(Msg));
}
