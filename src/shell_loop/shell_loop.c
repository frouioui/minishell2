/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** File of the shell_loop function : get input, parse and execute.
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"
#include "execution.h"

unsigned int shell_loop(shell_t *shell)
{
	char *user_input = NULL;
	unsigned int err = 0;

	display_prompt(shell);
	while ((user_input = get_next_line(0)) != NULL) {
		display_prompt(shell);
		shell->command_line = get_command_line(user_input, shell->env);
		if (shell->command_line == NULL)
			return (FAILURE);
		err = execute_command(shell, shell->command_line);
	}
	return (SUCCESS);
}
