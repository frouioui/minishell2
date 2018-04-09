/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** File of the shell_loop function : get input, parse and execute.
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"
#include "execution.h"

unsigned int redirect_loop(shell_t *shell, char *user_input)
{
	if (my_strlen(user_input) > 0) {
		shell->command_line = get_command_line(user_input, shell->env);
		if (shell->command_line == NULL)
			return (FAILURE);
		shell->code = execute_command(shell, shell->command_line);
		free_command(shell->command_line);
		update_backup(shell);
		free(user_input);
	}
	return (SUCCESS);
}

unsigned int shell_loop(shell_t *shell)
{
	char *user_input = NULL;

	display_prompt(shell);
	while (shell->state == OK && (user_input = get_next_line(0)) != NULL) {
		if (redirect_loop(shell, user_input) == FAILURE)
			return (FAILURE);
		display_prompt(shell);
	}
	return (SUCCESS);
}
