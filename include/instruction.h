/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the instruction structures and functions.
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

#define INSTRUCTION_SEPARATOR  ';'
#define PIPE_SEPARATOR '|'
#define ENV_VARIABLE_CHAR '$'
#define REDIRECT_CHAR(c) (c == '>' || c == '<')
#define SPACE_TAB(c) (c == ' ' || c == '\t')
#define DIGIT(c) (c >= '0' && c <= '9')
#define ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define ALPHANUM(c) (DIGIT(c) || ALPHA(c))

typedef enum type_redirect_s {
	EMPTY_REDIR,
	STDOUT_SIMPLE,
	STDOUT_DOUBLE,
	STDIN_SIMPLE,
	STDIN_DOUBLE,
} redirect_t;

typedef enum error_syntax_s {
	EMPTY_ERR,
	INVALID_PIPE,
	INVALID_REDIRECT_NAME,
	AMBIGUOUS_REDIRECT
} error_syntax_t;

typedef struct pipe_s {
	char *full_instruction;
	char **args;
	bool valid;
	bool redirect;
	error_syntax_t error;
	redirect_t type_redirect;
	int fd;
	char *file_redirect;
	char *path_exec;
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
	bool valid;
} command_line_t;

unsigned int get_number_instruction(char *user_input);
command_line_t *get_command_line(char *user_input, char **env);
unsigned int fill_up_instruction(instruction_t **insturction, char **env);
unsigned int get_pipe_number(instruction_t *instruction);
pipe_t **get_pipe(instruction_t *instruction, char **env);
unsigned int get_redirect(pipe_t **pipe, unsigned int number_of_pipe);
unsigned int analyse_redirect(pipe_t *pipe);
void check_env_variable(char **args, char **env);
void fix_extra_spaces(char *str);
void display_error_instruction(instruction_t *instruction);

#endif /* end of include guard: INSTRUCTION_H */
