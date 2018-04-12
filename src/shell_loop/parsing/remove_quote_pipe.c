/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Function that will remove all the quote on each side of a (char *)
*/

#include <stdlib.h>
#include "instruction.h"
#include "mylib.h"

static void adjust_frontwards(char *arg)
{
	unsigned int i = 0;

	while (arg[i + 1]) {
		arg[i] = arg[i + 1];
		i++;
	}
	arg[i] = '\0';
}

static void adjust_backwards(char *arg)
{
	unsigned int i = my_strlen(arg) - 1;

	arg[i] = '\0';
}

void remove_quote(char **args)
{
	for (unsigned int i = 0; args[i] != NULL; i++) {
		if (args[i][0] == 34 && args[i][my_strlen(args[i]) - 1]
			== 34) {
			adjust_frontwards(args[i]);
			adjust_backwards(args[i]);
		}
	}
}
