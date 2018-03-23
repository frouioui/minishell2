/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Fill the whole instruction structure after the expression was given
*/

#include <stdlib.h>
#include "shell.h"
#include "instruction.h"

unsigned int fill_up_instruction(instruction_t **instruction)
{
	for (unsigned int i = 0; instruction[i]; i++) {
		instruction[i]->valid = true;
		get_pipe_number(instruction[i]);
		instruction[i]->actual_pipe = 0;
		if (instruction[i]->valid == true)
			instruction[i]->pipe = get_pipe(instruction[i]);
		if (instruction[i]->valid && instruction[i]->pipe == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}
