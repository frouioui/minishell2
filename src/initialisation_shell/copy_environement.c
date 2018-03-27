/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Inits the whole shell's variable and structures.
*/

#include <stdlib.h>
#include "shell.h"
#include "mylib.h"

char **copy_environement(char **origin)
{
	unsigned int number_row = my_number_row(origin);
	char **env = malloc(sizeof(char *) * (number_row + 1));

	if (env == NULL)
		return (NULL);
	for (unsigned int i = 0; i < number_row; i++) {
		env[i] = malloc(sizeof(char) * (my_strlen(origin[i]) + 1));
		if (env[i] == NULL)
			return (NULL);
		my_strcpy(env[i], origin[i]);
	}
	env[number_row] = NULL;
	return (env);
}
