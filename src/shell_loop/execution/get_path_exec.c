/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Gets the correct file path for executable
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "mylib.h"
#include "execution.h"
#include "instruction.h"

static char *get_test_path(char *path, char *file, int *i)
{
	char *test = malloc(sizeof(char) *
		(my_strlen(path) + my_strlen(file) + 2));
	int count = 0;
	int a = *i;

	for (a = a; path[a] != ':' && path[a] != '\0'; a++) {
		test[count] = path[a];
		count++;
	}
	test[count++] = '/';
	for (int j = 0; file[j] && file[j] != ' ' && file[j] != '\t'; j++) {
		test[count] = file[j];
		count++;
	}
	test[count] = '\0';
	*i = a;
	if (access(test, X_OK) == -1) {
		free(test);
		return (NULL);
	}
	return (test);
}

static char *get_path_builtin(char *path, char *file, shell_t *shell)
{
	int i = 0;
	char *path_ok = NULL;
	int max = my_strlen(path);

	if (path == NULL)
		exit(84);
	while (i < max && path_ok == NULL) {
		path_ok = get_test_path(path, file, &i);
		i++;
	}
	return (path_ok);
}

char *get_path_exec(pipe_t *pipe, shell_t *shell)
{
	char *filename = NULL;
	char *path = my_get_env(shell->env, "PATH");

	path == NULL ? path = my_strcpy(path, shell->backup->path) : 0;
	filename = get_path_builtin(path, pipe->args[0], shell);
	if (filename == NULL)
		filename = get_execution_file_path(
			my_strcpy(NULL, pipe->args[0]), shell);
	if (filename == NULL) {
		display_error_execution(pipe->args[0]);
	}
	free(path);
	return (filename);
}
