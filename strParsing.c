#include "parse.h"
/**
 * strParsing - tokenizes a string into an arr of strings
 * @data: string to be tokenized
 * @dataContainer: duplication of string
 * @token: temp var to hold token
 * @Cmd: array to store the tokens
 *
 * Return: array of strings or NULL
 * if input is NULL or fails to allocate memory
 */
char **strParsing(char *data, char *dataContainer, char *token, char **Cmd)
{
	int i = 0, limiter = 1;

	if (!data)
		return (NULL);

	dataContainer = _strDuplicate(data);
	token = strtok(dataContainer, DELIMITER);

	Cmd = _INIT_TOKENS(&token, &limiter);

	if (Cmd)
	{
		while (token != NULL)
		{
		Cmd = parseToken(Cmd, &i, &limiter, token);
		if (!Cmd)
		{
		_freeMemo(dataContainer, data);
		return (NULL);
		}
		token = strtok(NULL, DELIMITER);
		}
	}
	else
	{
	_freeMemo(dataContainer, data);
	return (NULL);
	}

	Cmd[i] = NULL;
	_freeMemo(dataContainer, data);
	

	return (Cmd);
}
