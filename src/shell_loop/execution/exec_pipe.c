/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Recursive function for the execution of the pipes
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"
#include "instruction.h"

static void exec_parent(shell_t *shell, instruction_t *instruction, int **fd,
	int *stat)
{
	unsigned int actual = instruction->actual_pipe;

	if (dup_my_pipe(instruction, actual, fd) == -1)
		exit(84);
	/*if (is_builtins(instruction) == true) {
		if (exec_builtins(instruction->pipe[actual]) == -1)
			exit(84);
	} else {*/
		if (execve(instruction->pipe[actual]->path_exec,
		instruction->pipe[actual]->args, shell->env) == -1)
			display_error_exec(instruction, actual, shell);
		if (wait(stat) == -1)
			perror(instruction->pipe[actual]->args[0]);
	}
}

void exec_pipe(shell_t *shell, instruction_t *instruction, int **fd)
{
	pid_t pid = 0;
	int stat = 0;

	if ((pid = fork()) == -1)
		exit(84);
	if (pid == 0) {
		instruction->actual_pipe -= 1;
		exec_pipe(shell, instruction, fd);
		exit(0);
	} else {
		exec_parent(shell, instruction, fd, &stat);
	}
	check_end_exec(stat);
}
