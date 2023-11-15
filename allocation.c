#include "main.h"
/**
 * frees a 2d array
 */
void free_grid(int **grid, int height)
{
	int x;

	for (x = 0; x < height; x++)
	{
		free(grid[x]);
	}
	free(grid);
}
/**
 * works the same as realloc
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int x;
	char *arr;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		arr = malloc(new_size);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}

	arr = malloc(new_size);

	for (x = 0; x < old_size && x < new_size; x++)
	{
		arr[x] = ((char *) ptr)[x];
	}
	free(ptr);
	return (arr);
}
