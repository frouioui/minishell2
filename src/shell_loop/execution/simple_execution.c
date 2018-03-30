/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Simple execution functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

static void execute_child(shell_t *shell, pipe_t *pipe)
{
	int status = 0;
	pid_t pid = fork();

	if (pid == -1) {
		exit(84);
	} else if (pid == 0) {
		if (execve(pipe->path_exec, pipe->args, shell->env) == -1)
			errno == 8 ? bad_archi(shell, pipe->args[0])
			: perror(pipe->args[0]);
		exit(shell->code);
	} else {
		if (wait(&status) == -1)
			perror(pipe->args[0]);
		check_sig(status);
		if (status != 0 && shell->code == 0)
			shell->code = status / 256;
	}
}

void simple_execution(shell_t *shell, instruction_t *instruction)
{
	if (is_builtins(instruction->pipe[0]->args[0]) == true) {
	//	redirect_pipe(instruction->pipe[0]);
		if (exec_builtins(shell, instruction->pipe[0]) == -1)
			exit(1);
	} else if ((instruction->pipe[0]->path_exec =
		get_path_exec(instruction->pipe[0], shell)) != NULL) {
	//	redirect_pipe(instruction->pipe[0]);
		execute_child(shell, instruction->pipe[0]);
	} else {
		shell->code = 1;
	}
}
