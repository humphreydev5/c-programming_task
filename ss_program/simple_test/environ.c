#include "shell.h"

/**
 * _m_env - To prints the current shell environment
 * @infos: Arguments structure container.
 * Return: 0 Always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - To gets the value of an environ variable in shell
 * @info: Arguments structure container
 * @name: env var name
 *
 * Return: value
 */
char *_getenv(info_t *infos, const char *name)
{
	list_t *node = infos->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - New environment variable is initialize
 * @infos: Arguments structure container
 *  Return: 0 always
 */
int _mysetenv(info_t *infos)
{
	if (infos->argc != 3)
	{
		_eputs("Invalid number of arguements\n");
		return (1);
	}
	if (_setenv(infos, infos->argv[1], infos->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - To remove an environment variable in the shell
 * @infos: Arguments structure container
 * Return: 0 always
 */
int _myunsetenv(info_t *infos)
{
	int k;

	if (infos->argc == 1)
	{
		_eputs("Few arguements.\n");
		return (1);
	}
	for (k = 1; k <= infos->argc; k++)
		_unsetenv(infos, infos->argv[k]);

	return (0);
}

/**
 * populate_env_list - To populates env linked list
 * @infos: Arguments structure container
 * Return: 0 always
 */
int populate_env_list(info_t *infos)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	infos->env = node;
	return (0);
}
