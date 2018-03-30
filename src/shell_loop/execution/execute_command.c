/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Main file of the "execution" functions
*/

#include "shell.h"
#include "instruction.h"
#include "execution.h"

unsigned int execute_command(shell_t *shell, command_line_t *command)
{
	for (unsigned int nb = 0; command->instruction[nb] &&
	shell->state == OK; nb++) {
		if (command->instruction[nb]->valid == true &&
		command->instruction[nb]->number_of_pipe > 1) {
			multiple_execution(shell, command->instruction[nb]);
		} else if (command->instruction[nb]->valid == true){
			simple_execution(shell, command->instruction[nb]);
		}
	}
	return (shell->state);
}
