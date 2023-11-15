#include "shell.h"

/**
 * _history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @ifo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _history(info_t *ifo)
{
	print_list(ifo->history);
	return (0);
}

/**
 * _alias - sets alias to string
 * @ifo: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _alias(info_t *ifo, char *str)
{
	char *a, c;
	int ret;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	c = *a;
	*a = 0;
	ret = delete_node_at_index(&(ifo->alias),
		get_node_index(info->alias, node_starts_with(ifo->alias, str, -1)));
	*a = c;
	return (ret);
}

/**
 * _alias - sets alias to string
 * @ifo: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _alias(info_t *ifo, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(ifo, str));

	unset_alias(ifo, str);
	return (add_node_end(&(ifo->alias), str, 0) == NULL);
}

/**
 * p_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int p_alias(list_t *node)
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
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
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
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
