#include "shell.h"

/**
 * Frees a pointer and NULLs the address
 */
int bfreee(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
