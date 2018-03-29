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
#include <unistd.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static void exec_parent(shell_t *shell, instruction_t *inst, int **fd)
{
	unsigned int actual = inst->actual_pipe;

	/*if (is_builtins(instruction) == true) {
		if (dup_my_pipe(instruction, actual, fd) == -1)
			exit(84);
		if (exec_builtins(instruction->pipe[actual]) == -1)
			exit(84);
	} else {*/
	inst->pipe[actual]->path_exec = get_path_exec(inst->pipe[actual], shell);
	inst->pipe[actual]->path_exec == NULL ? exit(0) : 0;
	dup_my_pipe(inst, actual, fd) == -1 ? exit(84) : 0;
	if (execve(inst->pipe[actual]->path_exec, inst->pipe[actual]->args, shell->env) == -1)
		perror(inst->pipe[actual]->args[0]);
	//}
}

void exec_pipe(shell_t *shell, instruction_t *instruction, int **fd, pid_t pid)
{
	pid_t pid2 = 0;
	int stat = 0;

	if ((pid2 = fork()) == -1)
		exit(84);
	if (pid2 == 0) {
		instruction->actual_pipe--;
		if (instruction->actual_pipe > 0) {
			exec_pipe(shell, instruction, fd, pid2);
		} else if (instruction->actual_pipe == 0) {
			exec_parent(shell, instruction, fd);
		}
	} else {
		exec_parent(shell, instruction, fd);
	}
}
