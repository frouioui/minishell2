/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Include file of the instruction structures and functions.
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

#define CHAR_INSTRUCTION_SEPARATOR  ';'

typedef enum type_redirect_s {
	STDOUT_SIMPLE,
	STDOUT_DOUBLE,
	STDIN_SIMPLE,
	STDIN_DOUBLE
} redirect_t;

typedef struct pipe_s {
	char *full_instruction;
	char **args;
	bool redirect;
	redirect_t type_redirect;
	char *file_redirect;
} pipe_t;

typedef struct instruction_s {
	char *full_instruction;
	unsigned int number_of_pipe;
	unsigned int actual_pipe;
	pipe_t **pipe;
} instruction_t;

typedef struct command_line_s {
	unsigned int number_instruction;
	instruction_t **instruction;
} command_line_t;

unsigned int get_number_instruction(char *user_input);
command_line_t *get_command_line(char *user_input);

#endif /* end of include guard: INSTRUCTION_H */
