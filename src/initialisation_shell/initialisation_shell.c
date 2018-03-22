/*
** EPITECH PROJET, 2018
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
	shell->command_line = malloc(sizeof(command_line_t));
	if (shell->command_line == NULL || shell->backup == NULL)
		return (NULL);
	shell->command_line->instruction = NULL;
	shell->command_line->number_instruction = 0;
	return (shell);
}
