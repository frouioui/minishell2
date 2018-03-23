/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Get the whole pipe instructions
*/

#include <stdlib.h>
#include "shell.h"
#include "instruction.h"
#include "mylib.h"

static void scan_redirect(char *inst, int *i)
{
	
}

static unsigned int analyse_redirect(pipe_t *pipe)
{
	for (int i = 0; pipe->full_instruction[i] && pipe->valid; i++) {
		if (REDIRECT_CHAR(pipe->full_instruction[i]) == true) {
			scan_redirect(pipe->full_instruction, &i);
		}
	}
	return (0);
}

unsigned int get_redirect(pipe_t **pipe)
{
	for (unsigned int i = 0; pipe[i]; i++) {
		analyse_redirect(pipe[i]);
	}
	return (SUCCESS);
}
