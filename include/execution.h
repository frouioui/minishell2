/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Include file of the execution functions group
*/

#ifndef EXECUTION_H
#define EXECUTION_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"
#include "instruction.h"

#define NB_BUILTIN 5

/* --- functions redirection sturcture --- */
typedef struct redirect_flag_s {
	char *name;
	int (*built)(shell_t *, pipe_t *);
} redir_builtins_t;

/* --- standard commands functions --- */
unsigned int execute_command(shell_t *shell, command_line_t *command);
void multiple_execution(shell_t *shell, instruction_t *instruction);
void simple_execution(shell_t *shell, instruction_t *instruction);
unsigned int execute_command(shell_t *shell, command_line_t *command);
int **create_pipe(int nb);
void check_end_exec(int stat);
void exec_pipe(shell_t *shell, instruction_t *instruction, int **fd, pid_t);
int dup_my_pipe(instruction_t *instruction, unsigned int actual, int **fd);
void redirect_pipe(pipe_t *pipe);
void display_error_execution(char *filename);
char *get_path_exec(pipe_t *pipe, shell_t *shell);
char *get_execution_file_path(char *exec, shell_t *shell);
void exit_prog(int code);
void simple_execution(shell_t *shell, instruction_t *instruction);
void check_sig(shell_t *shell, int status);
void bad_archi(shell_t *shell, char *arg);
char *get_redirect_filename(pipe_t *pipe);
void redirect_stdin_double(pipe_t *pipe_act);

/* --- builtins functions --- */
int exec_builtins(shell_t *shell, pipe_t *pipe);
bool is_builtins(char *arg);
int cd_built(shell_t *shell, pipe_t *pipe);
int env_built(shell_t *shell, pipe_t *pipe);
int exit_built(shell_t *shell, pipe_t *pipe);
int setenv_built(shell_t *shell, pipe_t *pipe);
int unsetenv_built(shell_t *shell, pipe_t *pipe);
void folder_error(shell_t *shell, int err, char *folder);
unsigned int check_rollback_path(shell_t *, char *, unsigned int);
void go_home_cd(shell_t *shell);
void go_back_cd(shell_t *shell);
char *cd_special_cases(char *folder, char *env, int *changed);
static char *get_name_variable(char *env, char *name, int *i);
void save_old_pwd(char **env);
void put_new_old_pwd(shell_t *shell, char *buffer);
void restore_redirect(pipe_t *pipe);

#endif /* end of include guard: EXECUTION_H */
