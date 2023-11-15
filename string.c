#include "shell.h"

/**
 * returns the length of a string
 */
int _strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
 * performs lexicogarphic comparison of two strangs.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * checks if needle starts with haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * concatenates two strings
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

void bfree(void **buffer)
{
    if (buffer)
    {
        int i;
        for (i = 0; buffer[i]; ++i)
        {
            free(buffer[i]); /* Free each element in the buffer */
        }
        free(buffer); /* Free the buffer itself */
    }
}