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

unsigned int execute_command(shell_t *shell, command_line_t *command);
void multiple_execution(shell_t *shell, instruction_t *instruction);
unsigned int execute_command(shell_t *shell, command_line_t *command);
int **create_pipe(int nb);
void check_end_exec(int stat);
void exec_pipe(shell_t *shell, instruction_t *instruction, int **fd, pid_t);
int dup_my_pipe(instruction_t *instruction, unsigned int actual, int **fd);
void redirect_pipe(pipe_t *pipe, int *fd);
void display_error_execution(char *filename);
char *get_path_exec(pipe_t *pipe, shell_t *shell);
char *get_execution_file_path(char *exec, shell_t *shell);
void exit_prog(int code);
void simple_execution(shell_t *shell, instruction_t *instruction);
void check_sig(int status);

#endif /* end of include guard: EXECUTION_H */
