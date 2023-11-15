#include "shell.h"

/**
 * displays the history list, one command by line, preceded
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * sets alias to string
 */
int unset_aliass(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * sets alias to string
 */
int set_aliass(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_aliass(info, str));

	unset_aliass(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * prints an alias string
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * mimics the alias builtin (man alias)
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_aliass(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_aliass(info, info->argv[i]);
		else
			print_aliass(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
