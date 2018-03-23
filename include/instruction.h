/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Include file of the instruction structures and functions.
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

#define INSTRUCTION_SEPARATOR  ';'
#define PIPE_SEPARATOR '|'
#define REDIRECT_CHAR(c) (c == '>' || c == '<')

typedef enum type_redirect_s {
	EMPTY,
	STDOUT_SIMPLE,
	STDOUT_DOUBLE,
	STDIN_SIMPLE,
	STDIN_DOUBLE,
	STDERR_SIMPLE,
	STDERR_DOUBLE
} redirect_t;

typedef enum error_syntax_s {
	INVALID_PIPE,
	INVALID_REDIRECT_NAME
} error_syntax_t;

typedef struct pipe_s {
	char *full_instruction;
	char **args;
	bool valid;
	bool redirect;
	error_syntax_t error;
	redirect_t type_redirect;
	int fd_redirect;
	char *file_redirect;
} pipe_t;

typedef struct instruction_s {
	char *full_instruction;
	unsigned int number_of_pipe;
	unsigned int actual_pipe;
	bool valid;
	error_syntax_t error;
	pipe_t **pipe;
} instruction_t;

typedef struct command_line_s {
	unsigned int number_instruction;
	instruction_t **instruction;
} command_line_t;

unsigned int get_number_instruction(char *user_input);
command_line_t *get_command_line(char *user_input);
unsigned int fill_up_instruction(instruction_t **insturction);
unsigned int get_pipe_number(instruction_t *instruction);
pipe_t **get_pipe(instruction_t *instruction);

#endif /* end of include guard: INSTRUCTION_H */
