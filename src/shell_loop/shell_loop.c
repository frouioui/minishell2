/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** File of the shell_loop function : get input, parse and execute.
*/

#include <stdlib.h>
#include "shell.h"

unsigned int shell_loop(shell_t *shell)
{
	char *user_input = NULL;

	while ((user_input = get_next_line(0)) != NULL) {
		shell->command_line = get_command_line(user_input);
		if (shell->command_line == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}
