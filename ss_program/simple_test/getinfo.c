#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @infos: struct address
 */
void clear_info(info_t *infos)
{
	infos->arg = NULL;
	infos->argv = NULL;
	infos->path = NULL;
	infos->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @infos: struct address
 * @av: argument vector
 */
void set_info(info_t *infos, char **av)
{
	int i = 0;

	infos->fname = av[0];
	if (infos->arg)
	{
		infos->argv = strtow(infos->arg, " \t");
		if (!infos->argv)
		{
			infos->argv = malloc(sizeof(char *) * 2);
			if (infos->argv)
			{
				infos->argv[0] = _strdup(infos->arg);
				infos->argv[1] = NULL;
			}
		}
		for (i = 0; infos->argv && infos->argv[i]; i++)
			;
		infos->argc = i;

		replace_alias(infos);
		replace_vars(infos);
	}
}

/**
 * free_info - frees info_t struct fields
 * @infos: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *infos, int all)
{
	ffree(infos->argv);
	infos->argv = NULL;
	infos->path = NULL;
	if (all)
	{
		if (!infos->cmd_buf)
			free(infos->arg);
		if (infos->env)
			free_list(&(infos->env));
		if (infos->history)
			free_list(&(infos->history));
		if (infos->alias)
			free_list(&(infos->alias));
		ffree(infos->environ);
			infos->environ = NULL;
		bfree((void **)infos->cmd_buf);
		if (infos->readfd > 2)
			close(infos->readfd);
		_putchar(BUFF_FLUSH);
	}
}
