#include "shell.h"

/**
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
	return (0);
}
