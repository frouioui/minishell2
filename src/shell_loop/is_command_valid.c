/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Check if all the instruction are valid and if not display the error.
*/

#include <stdbool.h>
#include "instruction.h"

static bool display_error(instruction_t *instruction)
{
	for (int i = 0; instruction->pipe[i]; i++) {
		if (instruction->pipe[i]->valid == false)
			printf("error\n");
	}
	return (false);
}

bool is_command_valid(command_line_t *command)
{
	for (unsigned int i = 0; i < command->number_instruction; i++) {
		if (command->instruction[i]->valid == false)
			return (display_error(command->instruction[i]));
	}
	return (true);
}
