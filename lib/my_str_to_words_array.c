/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Function that manage parsing
*/

#include <stdlib.h>

static char *copy_args(char *line, int *j)
{
	int size = 0;
	int i = 0;
	char *tab_i = NULL;

	for (int i = *j; line[i] != ' ' && line[i] != '\n' && line[i] != '\0';
	i += 1)
		size += 1;
	tab_i = malloc(sizeof(*tab_i) * (size + 1));
	if (tab_i == NULL)
		return (NULL);
	for (i = 0; line[*j] != ' ' && line[*j] != '\n' && line[*j] != '\0';
	i += 1) {
		tab_i[i] = line[*j];
		*j += 1;
	}
	*j += 1;
	tab_i[i] = '\0';
	return (tab_i);
}

char **cut_line(char *line)
{
	char **tab_arg = NULL;
	int nb_arg = 1;
	int j = 0;

	for (int i = 0; line[i] != '\n' && line[i] != '\0'; i += 1)
		if (line[i] == ' ')
			nb_arg += 1;
	tab_arg = malloc(sizeof(*tab_arg) * (nb_arg + 1));
	if (tab_arg == NULL)
		return (NULL);
	for (int i = 0; i < nb_arg; i += 1) {
		tab_arg[i] = copy_args(line, &j);
	}
	tab_arg[nb_arg] = NULL;
	return (tab_arg);
}
