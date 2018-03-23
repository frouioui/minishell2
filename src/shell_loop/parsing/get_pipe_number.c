/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Get the number of instruction in the user input.
*/

#include <stdlib.h>
#include "instruction.h"

static unsigned int seek_next_separator(instruction_t *instruction, int *i)
{
	(*i) += 1;
	while (instruction->full_instruction[*i] == ' ' &&
	instruction->full_instruction[*i])
		(*i) += 1;
	if (instruction->full_instruction[*i] == '\0')
		return (0);
	if (instruction->full_instruction[*i] == PIPE_SEPARATOR) {
		instruction->valid = false;
		instruction->error = INVALID_PIPE;
	}
	return (1);
}

unsigned int get_pipe_number(instruction_t *instruction)
{
	unsigned int pipe = 1;

	for (int i = 0; instruction->full_instruction[i] &&
	instruction->valid == true; i++) {
		if (instruction->full_instruction[i] == PIPE_SEPARATOR)
			pipe += seek_next_separator(instruction, &i);
	}
	instruction->number_of_pipe = pipe;
	if (instruction->valid == false)
		return (0);
	return (pipe);
}
