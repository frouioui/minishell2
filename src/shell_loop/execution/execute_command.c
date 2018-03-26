/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Main file of the "execution" functions
*/

#include "shell.h"
#include "instruction.h"
#include "execution.h"

unsigned int execute_command(shell_t *shell, command_line_t *command)
{
	for (unsigned int nb = 0; command->instruction[nb]; nb++) {
		if (command->instruction[nb]->number_of_pipe > 1) {
			multiple_execution(shell, command->instruction[nb]);
		} else {
			// simple execution
		}
	}
	return (0);
}
