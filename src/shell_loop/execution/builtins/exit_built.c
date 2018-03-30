/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** __DESCRIPTION__
*/

#include "shell.h"
#include "instruction.h"

int exit_built(shell_t *shell, pipe_t *pipe)
{
	shell->state = 1;
	return (0);
}
