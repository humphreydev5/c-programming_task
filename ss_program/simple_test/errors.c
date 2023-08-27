#include "shell.h"

/**
 * _eputs - To print input string
 * @str: String to printed
 *
 * Return: null
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @ch: The character to print
 *
 * Return: 1 on success.
 * Error, return -1.
 */
int _eputchar(char ch)
{
	static int k;
	static char buff[WRITE_BUFF_SIZE];

	if (ch == BUFF_FLUSH || k >= WRITE_BUFF_SIZE)
	{
		write(2, buff, k);
		k = 0;
	}
	if (ch != BUFF_FLUSH)
		buff[k++] = ch;
	return (1);
}

/**
 * _putfd - To write character ch to given filedescriptor
 * @ch: Character to print
 * @fd: Filedescriptor to write to
 *
 * Return: 1 on success.
 * Error, return -1
 */
int _putfd(char ch, int fd)
{
	static int k;
	static char buff[WRITE_BUFF_SIZE];

	if (ch == BUFF_FLUSH || k >= WRITE_BUFF_SIZE)
	{
		write(fd, buff, k);
		k = 0;
	}
	if (ch != BUFF_FLUSH)
		buff[k++] = ch;
	return (1);
}

/**
 * _putsfd - To write character ch to given filedescriptor
 * @str: String to print
 * @fd: Filedescriptor to write to
 *
 * Return: number of chars put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}
