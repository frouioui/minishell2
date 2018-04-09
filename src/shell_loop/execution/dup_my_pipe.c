/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Dup the pipe's file descriptor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "execution.h"
#include "instruction.h"

static void dup_first(pipe_t *pipe, int *fd)
{
	if (dup2(fd[1], 1) == -1)
		perror("dup");
	if (pipe->redirect == true)
		redirect_pipe(pipe);
	close(fd[0]);
}

static void dup_last(pipe_t *pipe, int *fd)
{
	if (dup2(fd[0], 0) == -1)
		perror("dup");
	if (pipe->redirect == true)
		redirect_pipe(pipe);
	close(fd[1]);
}

static void dup_between(pipe_t *pipe, int *fd, int *fd2)
{
	if (pipe->redirect == true)
		redirect_pipe(pipe);
	if (pipe->type_redirect != STDOUT_SIMPLE &&
	pipe->type_redirect != STDOUT_DOUBLE)
		if (dup2(fd[1], 1) == -1)
			perror("dup");
	if (pipe->type_redirect != STDIN_SIMPLE &&
	pipe->type_redirect != STDIN_DOUBLE)
		if (dup2(fd2[0], 0) == -1)
			perror("dup");
	close(fd[0]);
	close(fd2[1]);
}

int dup_my_pipe(instruction_t *instruction, unsigned int actual, int **fd)
{
	if (actual == 0) {
		dup_first(instruction->pipe[actual], fd[actual]);
	} else if (actual == instruction->number_of_pipe - 1) {
		dup_last(instruction->pipe[actual], fd[actual - 1]);
	} else {
		dup_between(instruction->pipe[actual], fd[actual],
		fd[actual - 1]);
	}
	return (0);
}
