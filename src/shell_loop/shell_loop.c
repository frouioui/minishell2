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

bool is_empty_input(char *user_input)
{
	for (int i = 0; user_input[i]; i++) {
		if (SPACE_TAB(user_input[i]) == 0)
			return (true);
	}
	return (false);
}

unsigned int redirect_loop(shell_t *shell, char *user_input)
{
	if (is_empty_input(user_input) == true) {
		user_input = apply_transformation(shell->bonus, user_input);
		shell->command_line = get_command_line(shell->bonus,
			user_input, shell->env);
		if (shell->command_line == NULL)
			return (FAILURE);
		shell->code = execute_command(shell, shell->command_line);
		write_command_history(shell->bonus, shell->command_line);
		free_command(shell->command_line);
		update_backup(shell);
		free(user_input);
	}
	return (SUCCESS);
}

unsigned int shell_loop(shell_t *shell)
{
	char *user_input = NULL;

	while (shell->state == OK && display_prompt(shell) &&
		(user_input = get_next_line(0)) != NULL) {
		if (redirect_loop(shell, user_input) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
