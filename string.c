#include "main.h"
/**
 * works the same as strlen
 */
int _strlen(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}
	return (c);
}
/**
 * converts string to an integar
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int nb = 0;
	signed int nb1 = 0;

	for (; *s != '\0'; s++)
	{
		if (*s == ' ' || *s == '+' || *s == '-')
		{
			if ((*s == '-' && sign == 1) || (*s == '+' && sign == -1))
			{
				sign = -1;
			}
			else if (*s == '-' && sign == -1)
			{
				sign = 1;
			}
		}
		if (*s >= '0' && *s <= '9')
		{
			nb = nb + (*s - '0');
			if (*(s + 1) < '0' || *(s + 1) > '9')
			{
				break;
			}
			else
			{
				nb = nb * 10;
			}
		}
	}
	if (sign == -1)
	{
		nb1 = nb * sign;
		return (nb1);
	}
	return (nb * sign);
}
/**works the same as strcmp
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0';)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		s1++;
		s2++;
	}
	return (0);
}
/**
 * search for char c in string s
 */
char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] == c)
		{
			return (s + a);
		}
	}
	if (c == '\0')
	{
		return (s + a);
	}
	return ('\0');
}
