#include "shell.h"

/**
 * _m_history - Show the history list, one command by line, then preceded
 *              with line numbers, beginning with 0.
 * @infos: Arguments structure container. To maintain
 * constant functions prototype.
 *  Return: ALways 0
 */
int _m_history(info_t *infos) /* my history function */
{
	print_list(infos->history);
	return (0);
}

/**
 * unset_alias - alias sets to string
 * @infos: the parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error always
 */
int unsets_alias(info_t *infos, char *str)
{
	char *p, ch;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	ch = *p;
	*p = 0;
	ret = delete_node_at_index(&(infos->alias),
		get_node_index(infos->alias, node_starts_with(infos->alias, str, -1)));
	*p = ch;
	return (ret);
}

/**
 * sets_alias - alias sets to string
 * @infos: the parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error always
 */
int sets_alias(info_t *infos, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsets_alias(infos, str));

	unsets_alias(infos, str);
	return (add_node_end(&(infos->alias), str, 0) == NULL);
}

/**
 * print_alias - To prints an alias string in the shell
 * @node: node alias
 *
 * Return: 0 on success, 1 on error always
 */
int print_alias(list_t *node)
{
	char *p = NULL, *r = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (r = node->str; r <= p; r++)
		_putchar(*r);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _m_alias - To mimics the alias builtin (man alias)
 * @infos: Arguments structure container. To maintain
 * constant functions prototype.
 *  Return: ) 0 always 
 */
int _m_alias(info_t *infos)
{
	int k = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infos->argc == 1)
	{
		node = infos->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (k = 1; infos->argv[k]; k++)
	{
		p = _strchr(infos->argv[k], '=');
		if (p)
			sets_alias(infos, infos->argv[k]);
		else
			print_alias(node_starts_with(infos->alias, infos->argv[k], '='));
	}

	return (0);
}
