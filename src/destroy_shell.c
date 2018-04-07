/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Destroy the shell, and returns the last code value.
*/

#include <stdlib.h>
#include "shell.h"

static void destroy_backup(backup_t *backup)
{
	free(backup->user);
	free(backup->path);
	free(backup->home);
	free(backup->current_pwd);
	free(backup);
}

int destroy_shell(shell_t *shell)
{
	int code = shell->code;

	destroy_backup(shell->backup);
	free_array_string(shell->env);
	free(shell);
	return (code);
}
