/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Main file for all the "multiple execution" command (pipes)
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"

void multiple_execution(shell_t *shell, instruction_t *instruction)
{
	pid_t pid = 0;
	int **fd = create_pipe(instruction->number_of_pipe);
	int stat = 0;
	int actual = instruction->actual_pipe;

	if (fd == NULL || (pid = fork()) == -1)
		exit(84);
	if (pid == 0) {
		exec_pipe(shell, instruction, fd);
	} else {
		if (wait(&stat) == -1)
			perror(instruction->pipe[actual]->args[0]);
	}
	check_end_exec(stat);
}
