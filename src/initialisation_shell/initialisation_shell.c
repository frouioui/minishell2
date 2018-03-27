/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include "shell.h"
#include "echec.h"

shell_t *initialisation_shell(char **env)
{
	shell_t *shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (NULL);
	if (env != NULL)
		shell->env = copy_environement(env);
	else
		shell->env = set_env_echec_mode();
	if (shell->env == NULL)
		return (NULL);
	shell->backup = initialisation_backup(shell->env);
	shell->command_line = NULL;
	if (shell->backup == NULL)
		return (NULL);
	return (shell);
}
