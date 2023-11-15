#include "main.h"
/**
 * executes the command
 */
void execute(char **arr, char **av)
{
	int p, status;

	p = fork();
	if (p == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
}
/**
 * read a line from input
 */
ssize_t _getline(char **lineptr, ssize_t *n, int stream)
{
	ssize_t nread = 0;
	char *temp, *new_buff;

	temp = malloc(BUFFER);
	if (!temp)
		return (-1);

	while ((nread += read(stream, temp + nread, BUFFER)) > 0)
	{
		if (*n < nread + BUFFER)
		{
			*n += BUFFER;
			new_buff = _realloc(temp, sizeof(temp), sizeof(temp) + *n);
			if (!new_buff)
			{
				free(temp);
				return (-1);
			}
			temp = new_buff;
		}
		if (temp[nread - 1] == '\n')
			break;
	}
	if (nread == -1)
	{
		free(temp);
		return (-1);
	}
	temp[nread - 1] = '\0';
	*lineptr = temp;

	return (nread - 1);
}
