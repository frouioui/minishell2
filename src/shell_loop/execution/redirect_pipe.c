/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Redirect the pipe fd(s)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "execution.h"
#include "instruction.h"

static void redirect_stdout(pipe_t *pipe)
{
	if (pipe->type_redirect == STDOUT_SIMPLE)
		pipe->fd = open(pipe->file_redirect, O_CREAT | O_TRUNC |
			O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
			S_IROTH | S_IWOTH);
	if (pipe->type_redirect == STDOUT_DOUBLE)
		pipe->fd = open(pipe->file_redirect, O_WRONLY | O_CREAT |
		O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |
		S_IWOTH);
	pipe->fd == -1 ? exit(84) : 0;
	if (dup2(pipe->fd, 1) == -1)
		perror("dup2");
}

static void redirect_stdin(pipe_t *pipe)
{
	if (pipe->type_redirect == STDIN_SIMPLE) {
		pipe->fd = open(pipe->file_redirect, O_RDONLY);
		pipe->fd == -1 ? exit(84) : 0;
		if (dup2(pipe->fd, 0) == -1)
			perror("dup2");
	}
	if (pipe->type_redirect == STDIN_DOUBLE)
		redirect_stdin_double(pipe);
}

void redirect_pipe(pipe_t *pipe)
{
	if (pipe->redirect == false)
		return;
	pipe->file_redirect = get_redirect_filename(pipe);
	if (pipe->file_redirect == NULL)
		exit(84);
	if (pipe->type_redirect == STDOUT_SIMPLE ||
	pipe->type_redirect == STDOUT_DOUBLE) {
		redirect_stdout(pipe);
	} else if (pipe->type_redirect == STDIN_SIMPLE ||
	pipe->type_redirect == STDIN_DOUBLE) {
		redirect_stdin(pipe);
	}
}
