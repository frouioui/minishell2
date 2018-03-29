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

static void wait_all(int *stat, unsigned int nb_pipe, pipe_t **pipe, int **fd)
{
	unsigned int i = 0;

	if (stat == NULL)
		exit(84);
	while (i < nb_pipe - 1) {
		close(fd[i][1]);
		close(fd[i++][0]);
	}
	for (unsigned int i = 0; i < nb_pipe - 1; i++) {
		wait(&(stat[i]));
		check_sig(stat[i]);
	}
}

static int init_stat(int *stat, instruction_t *instruction)
{
	if (stat == NULL)
		return (-1);
	for (unsigned int i = 0; i < instruction->number_of_pipe; i++) {
		stat = 0;
	}
	return (1);
}

void multiple_execution(shell_t *shell, instruction_t *instruction)
{
	pid_t pid = 0;
	int **fd = create_pipe(instruction->number_of_pipe);
	int *stat = malloc(sizeof(int) * (instruction->number_of_pipe + 1));
	int actual = instruction->actual_pipe;

	if (!fd || !init_stat(stat, instruction) || (pid = fork()) == -1)
		exit(84);
	if (pid == 0) {
		exec_pipe(shell, instruction, fd, pid);
	} else {
		wait_all(stat, instruction->number_of_pipe, instruction->pipe,
			fd);
	}
}
