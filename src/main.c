/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Check if args == 1 and init the shell then call the shell function.
*/

#include <stdlib.h>
#include "shell.h"

int main(int argc, char **argv, char **env)
{
	shell_t *shell = NULL;

	if (check_args(argc) == FAILURE)
		return (FAILURE);
	shell = initialisation_shell(env);
	if (shell == NULL)
		return (FAILURE);
	if (shell_loop(shell) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
