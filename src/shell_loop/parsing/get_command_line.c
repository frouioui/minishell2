/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** File of the main parsing function.
*/

#include <stdlib.h>
#include "instruction.h"

command_line_t *get_command_line(char *user_input)
{
	command_line_t *command_line = malloc(sizeof(command_line_t));

	if (command_line == NULL)
		return (NULL);
	command_line->number_instruction = get_number_instruction(user_input);
}
