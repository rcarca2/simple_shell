#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_you - checks if character is a delimeter
 * @a: the char to check
 * @dima: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_you(char a, char *dima)
{
	while (*dima)
		if (*dima++ == a)
			return (1);
	return (0);
}

/**
 *_alpha - checks for alphabetic character
 *@b: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _alpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_toi - converts a string to an integer
 *@c: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _toi(char *c)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  c[i] != '\0' && flag != 2; i++)
	{
		if (c[i] == '-')
			sign *= -1;

		if (c[i] >= '0' && c[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

