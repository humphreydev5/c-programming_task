#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @infos: parameter struct
 * @buff: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buff(info_t *infos, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buff, &len_p, stdin);
#else
		r = _getline(infos, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			infos->linecout_flags = 1;
			remove_comments(*buff);
			build_history_list(infos, *buff, infos->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = r;
				infos->cmd_buf = buff;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @infos: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *infos)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buff_p = &(infos->arg), *p;

	_putchar(BUFF_FLUSH);
	r = input_buff(infos, &buff, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buff + i; /* get pointer for return */

		check_chain(infos, buff, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(infos, buff, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			infos->cmd_buf_type = CMD_NORM;
		}

		*buff_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buff_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @infos: parameter struct
 * @buff: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buff(info_t *infos, char *buff, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(infos->readfd, buff, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @infos: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *infos, char **ptr, size_t *length)
{
	static char buff[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buff(infos, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buff + i, k - i);
	else
		_strncpy(new_p, buff + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}
