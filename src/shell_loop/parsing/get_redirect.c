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

static void check_after_redirect(pipe_t *pipe, char *inst, int *i)
{
	while (inst[*i] && SPACE_TAB(inst[*i]))
		(*i)++;
	if (inst[*i] == '\0' || REDIRECT_CHAR(inst[*i])) {
		pipe->valid = false;
		pipe->error = INVALID_REDIRECT_NAME;
		pipe->type_redirect = EMPTY_REDIR;
		pipe->redirect = false;
		return;
	}
	while (inst[*i] && REDIRECT_CHAR(inst[*i]) == false)
		(*i)++;
	if (inst[*i] != '\0') {
		pipe->valid = false;
		pipe->error = AMBIGUOUS_REDIRECT;
		pipe->type_redirect = EMPTY_REDIR;
		pipe->redirect = false;
	} else {
		pipe->redirect = true;
	}
}

static void scan_redirect(pipe_t *pipe, char *inst, int *i)
{
	if (inst[*i] == '>') {
		if (inst[*i + 1] == '>' && SPACE_TAB(inst[*i + 2])) {
			pipe->type_redirect = STDOUT_DOUBLE;
			*i = *i + 2;
		} else if (SPACE_TAB(inst[*i + 1])) {
			pipe->type_redirect = STDOUT_SIMPLE;
			*i = *i + 1;
		}
	} else if (inst[*i] == '<') {
		if (inst[*i + 1] == '<' && SPACE_TAB(inst[*i + 2])) {
			pipe->type_redirect = STDIN_DOUBLE;
			*i = *i + 2;
		} else if (SPACE_TAB(inst[*i + 1])) {
			pipe->type_redirect = STDIN_SIMPLE;
			*i = *i + 1;
		}
	}
	check_after_redirect(pipe, inst, i);
}

unsigned int analyse_redirect(pipe_t *pipe)
{
	for (int i = 0; pipe->full_instruction[i] && pipe->valid; i++) {
		if (REDIRECT_CHAR(pipe->full_instruction[i])) {
			scan_redirect(pipe, pipe->full_instruction, &i);
		}
	}
	return (0);
}

unsigned int get_redirect(pipe_t **pipe, unsigned int number_of_pipe)
{
	for (unsigned int i = 0; i < number_of_pipe; i++) {
		analyse_redirect(pipe[i]);
	}
	return (SUCCESS);
}
