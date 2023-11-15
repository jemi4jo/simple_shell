#include "main.h"
int n_elements(char *str);
/**
 * makes a 2d array of a string
 */
char **make_array(char *str)
{
	char **arr;
	char *token;
	int i = 0;

	arr = malloc(sizeof(char *) * n_elements(str) + 1);

	token = my_strtok(str, " ");

	while (token != NULL)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		arr[i] = token;

		token = my_strtok(NULL, " ");
		i++;
	}
	arr[i] = NULL;

	return (arr);

}
/**
 * return number of array to be allocated
 */
int n_elements(char *str)
{
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j + 1);
}
/**
 * works as strtok
 */
char *my_strtok(char *str, char *delim)
{
	static char *ptr;
	char *nstr;

	if (str == NULL)
		str = ptr;

	nstr = str;

	if (*nstr == '\n' || *nstr == '\0')
		return (NULL);

	while (nstr != NULL && _strchr(delim, *nstr) == NULL)
		nstr++;

	if (nstr != NULL || *nstr != '\n')
	{
		*nstr = '\0';
		ptr = nstr + 1;
	}
	else
		ptr = NULL;

	return (str);
}
