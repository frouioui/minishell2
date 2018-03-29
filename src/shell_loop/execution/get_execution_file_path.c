/*
** EPITECH PROJECT, 2018
** get_execution_filename.c
** File description:
** Get the filepath of an executable
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "shell.h"
#include "instruction.h"
#include "execution.h"
#include "mylib.h"

static int count_rollback(char *user_input)
{
	int roll_back = 0;
	int i = 0;

	if (user_input[0] == '.' && user_input[1] == '/')
		return (0);
	while (user_input[i] == '.' || user_input[i] == '/') {
		if (user_input[i] == '/')
			roll_back++;
		i++;
	}
	return (roll_back);
}

static void roll_back_path(char *path, int roll_back)
{
	int i = my_strlen(path);

	while (i > 0 && roll_back != 0) {
		if (path[i] == '/')
			roll_back--;
		path[i] = '\0';
		i--;
	}
}

static int get_file_name(char *user)
{
	int i = 0;
	int gap = 0;

	if (user[0] != '.')
		return (-42);
	while (user[i] == '.' || user[i] == '/')
		i++;
	gap = i - 1;
	user[0] = '/';
	while (user[i] != '\0') {
		user[i - gap] = user[i];
		i++;
	}
	user[i - gap] = '\0';
	return (0);
}

char *get_execution_file_path(char *exec, shell_t *shell)
{
	char *path = my_strcpy(NULL, shell->backup->path);
	char *file = malloc(sizeof(char) * my_strlen(path) + my_strlen(exec));
	int roll_back = count_rollback(exec);
	int a = 0;

	a = get_file_name(exec);
	file == NULL ? exit_prog(84) : 0;
	if (roll_back > 0 && a > -1)
		roll_back_path(path, roll_back);
	for (int i = 0; a > -1 && path[i]; i++) {
		file[a] = path[i];
		a++;
	}
	a == -42 ? a = 0 : 0;
	for (int i = 0; exec[i] && exec[i] != ' '; a++) {
		file[a] = exec[i];
		file[a + 1] = '\0';
		i++;
	}
	return (access(file, X_OK) == -1 ? NULL : file);
}
