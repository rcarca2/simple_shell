#include "shell.h"

/**
<<<<<<< HEAD
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
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
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
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

=======
 * _yexit - exits the shell
 * @ifo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _yexit(info_t *ifo)
{
	int exitcheck;

	if (ifo->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(ifo->argv[1]);
		if (exitcheck == -1)
		{
			ifo->status = 2;
			print_error(ifo, "Illegal number: ");
			_eputs(ifo->argv[1]);
			_eputchar('\n');
			return (1);
		}
		ifo->err_num = _erratoi(ifo->argv[1]);
		return (-2);
	}
	ifo->err_num = -1;
	return (-2);
}

/**
 * _cd - changes the current directory of the process
 * @ifo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _cd(info_t *ifo)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!ifo->argv[1])
	{
		dir = _getenv(ifo, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(ifo, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(ifo->argv[1], "-") == 0)
	{
		if (!_getenv(ifo, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(ifo, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(ifo, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(ifo->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(ifo, "can't cd to ");
		_eputs(ifo->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(ifo, "OLDPWD", _getenv(ifo, "PWD="));
		_setenv(ifo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - changes the current directory of the process
 * @ifo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _help(info_t *ifo)
{
	char **arg_array;

	arg_array = ifo->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
>>>>>>> b4f0b738420717666b4860f14d3974456abfb091
	return (0);
}
