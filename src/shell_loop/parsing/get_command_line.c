/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** File of the main parsing function
*/

#include <stdlib.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static instruction_t *new_instruction(char *str)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (instruction == NULL)
		return (NULL);
	instruction->full_instruction = malloc(sizeof(char) *
		(my_strlen(str) + 1));
	if (instruction->full_instruction == NULL)
		return (NULL);
	return (instruction);
}

static unsigned int get_instruction(command_line_t *command, char *input)
{
	unsigned int j = 0;
	int i = 0;

	while (input[i] && j < command->number_instruction) {
		command->instruction[j] = new_instruction(input);
		if (command->instruction[j] == NULL)
			return (FAILURE);
		for (int a = 0; input[i] && input[i] != INSTRUCTION_SEPARATOR;
		a++) {
			command->instruction[j]->full_instruction[a]
			= input[i];
			i++;
			command->instruction[j]->full_instruction[a + 1] = 0;
		}
		for (i; input[i] && input[i] == ';' && input[i] == ' '; i++);
		j++;
		i++;
	}
	return (SUCCESS);
}

command_line_t *get_command_line(char *user_input)
{
	command_line_t *command_line = malloc(sizeof(command_line_t));

	if (command_line == NULL)
		return (NULL);
	command_line->number_instruction = get_number_instruction(user_input);
	command_line->instruction = malloc(sizeof(instruction_t *) *
		(command_line->number_instruction + 1));
	if (command_line->instruction == NULL)
		return (NULL);
	command_line->instruction[command_line->number_instruction] = NULL;
	if (get_instruction(command_line, user_input) == FAILURE)
		return (NULL);
	if (fill_up_instruction(command_line->instruction) == FAILURE)
		return (NULL);
	return (command_line);
}
