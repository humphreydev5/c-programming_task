#include "shell.h"

/**
 * _m_exit - To exit the shell environ
 * @infos: Arguments structure container. To maintain
 * constant functions prototype.
 * Return: exit when it is exit status
 * (0) if infos.argv[0] != "exit"
 */
int _m_exit(info_t *infos)
{
	int exitchecks;

	if (infos->argv[1]) /* there is an exit arguement */
	{
		exitchecks = _erratoi(infos->argv[1]);
		if (exitchecks == -1)
		{
			infos->status = 2;
			print_error(infos, "Unsupported number: ");
			_eputs(infos->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infos->err_num = _erratoi(infos->argv[1]);
		return (-2);
	}
	infos->err_num = -1;
	return (-2);
}

/**
 * _m_cd - To change the current working directory of the shell process
 * @infos: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 0 Always
 */
int _m_cd(info_t *infos)/* My cd function*/
{
	char *str, *dir, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg right here<<\n");
	if (!infos->argv[1])
	{
		dir = _getenv(infos, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what can this actually be? */
				chdir((dir = _getenv(infos, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(infos->argv[1], "-") == 0)
	{
		if (!_getenv(infos, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(infos, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what can this actually be? */
			chdir((dir = _getenv(infos, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(infos->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(infos, "can't change directory (cd) to ");
		_eputs(infos->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(infos, "OLDPWD", _getenv(infos, "PWD="));
		_setenv(infos, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - To change the current working directory of the shell process
 * @infos: Structure containing potential arguments. Used to maintain
 * constant functions prototype.
 * Return: 0 Always
 */
int _m_help(info_t *infos) /* My help function*/
{
	char **arg_arr;

	arg_arr = infos->argv;
	_puts("helps call works. Function not declared \n");
	if (0)
		_puts(*arg_arr); /* temporary att_unused workaround */
	return (0);
}
