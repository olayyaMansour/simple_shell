#include "main.h"

/**
 * custom_getline - reads a line from stdin using a buffer
 *
 * Return: dynamically allocated line or NULL on failure or EOF
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	static ssize_t bytes_read = 0;

	size_t line_size = 0;
	char *line = NULL;

	while (1)
	{
		if ((ssize_t)buffer_index >= bytes_read || bytes_read == 0)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (line != NULL)
					free(line);
				return NULL;
			}
			buffer_index = 0;
		}

		while ((ssize_t)buffer_index < bytes_read && buffer[buffer_index] != '\n')
		{
			line_size++;
			buffer_index++;

			line = realloc(line, (line_size + 1) * sizeof(char));
			if (line == NULL)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}

		memcpy(line + line_size - buffer_index, buffer, buffer_index);

		if ((ssize_t)buffer_index < bytes_read && buffer[buffer_index] == '\n')
		{
			line[line_size] = '\0';
			buffer_index++;
			return line;
		}
	}
}
