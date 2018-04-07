/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the main structures and functions.
*/

#ifndef SHELL_H
#define SHELL_H

#include "instruction.h"

#define SUCCESS 0
#define SKIP 21
#define FAILURE 84

typedef struct backup_s {
	char *user;
	char *path;
	char *home;
	char *current_pwd;
} backup_t;

typedef enum state_s {
	OK,
	EXIT,
	ERROR_84,
	ERROR_1
} state_t;

typedef struct shell_s {
	char **env;
	backup_t *backup;
	command_line_t *command_line;
	state_t state;
	int code;
} shell_t;

int check_args(int argc);
char **copy_environement(char **origin);
shell_t *initialisation_shell(char **env);
char **copy_environement(char **origin);
backup_t *initialisation_backup(char **env);
unsigned int shell_loop(shell_t *shell);
void display_prompt(shell_t *shell);
void free_array_string(char **array);
void update_backup(shell_t *shell);
int destroy_shell(shell_t *shell);

#endif /* end of include guard: SHELL_H */
