/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "instruction.h"
#include "mylib.h"

static char *cut_filename(char *instruction)
{
	char *filename = malloc(sizeof(char) * my_strlen(instruction));
	int i = 0;
	int a = 0;

	if (filename == NULL)
		return (NULL);
	while (REDIRECT_CHAR(instruction[i]) == 0 && instruction[i])
		i++;
	while (REDIRECT_CHAR(instruction[i]) && instruction[i])
		i++;
	while (SPACE_TAB(instruction[i]) && instruction[i])
		i++;
	while (instruction[i] && SPACE_TAB(instruction[i]) == 0) {
		filename[a] = instruction[i];
		i++;
		a++;
	}
	return (filename);
}

static void clear_redirected_pipe(char *instruction)
{
	int i = 0;

	while (instruction[i] && REDIRECT_CHAR(instruction[i]) == 0)
		i++;
	instruction[i] = '\0';
}

char *get_redirect_filename(pipe_t *pipe)
{
	char *filename = cut_filename(pipe->full_instruction);

	if (filename == NULL)
		return (filename);
	free_array_string(pipe->args);
	clear_redirected_pipe(pipe->full_instruction);
	pipe->args = cut_line(pipe->full_instruction);
	return (filename);
}
