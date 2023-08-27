#include "shell.h"

/**
 * interactive - returns true when the shell is in interactive
 * @infos: the address of the struct
 *
 * Return: 1 if the shell is in interactive mode, 0 if it's not in the interactive mode
 */
int interactive(info_t *infos)
{
	return (isatty(STDIN_FILENO) && infos->readfd <= 2);
}

/**
 * is_delim - To identify char that are delimeter
 * @ch: To know the char to check
 * @delim: represent the delimeter string in the shell
 * Return: 1 if the execution is true, 0 if the execution is false
 */
int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - To checks for alphabetical character
 * @ch: Character to input in the shell
 * Return: 1 if ch is alphabetic character, 0 if is not
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - To convert a strings into an integer type
 * @str: String to be converted
 * Return: 0 when there is no numbers in the string, convert to numbers otherwise
 */

int _atoi(char *str)
{
	int k, signs = 1, flags = 0, outputs;
	unsigned int result = 0;

	for (k = 0; str[k] != '\0' && flags != 2; k++)
	{
		if (str[k] == '-')
			signs *= -1;

		if (str[k] >= '0' && str[k] <= '9')
		{
			flags = 1;
			result *= 10;
			result += (str[k] - '0');
		}
		else if (flags == 1)
			flags = 2;
	}

	if (signs == -1)
		outputs = -result;
	else
		outputs = result;

	return (outputs);
}
