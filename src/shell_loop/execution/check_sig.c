/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Check if there was any signal in the child process
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

char *add_core_dump(char *base)
{
	int i = my_strlen(base);
	char *str = " (core dumped)\n";
	char *new = malloc(sizeof(char) * (i + my_strlen(str) + 2));

	if (new == NULL)
		exit(84);
	my_strcpy(new, base);
	for (int a = 0; str[a]; a++) {
		new[i] = str[a];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void check_sig(int stat)
{
	char *str = NULL;
	int nb = (stat >= 128 ? stat - 128 : stat);

	if (WIFSIGNALED(stat)) {
		str = my_strcpy(NULL, sys_siglist[nb]);
		if (WCOREDUMP(stat))
			str = add_core_dump(str);
		my_putstr(str);
	} else if (WIFSTOPPED(stat)) {
		my_putstr("Stopped\n");
	}
	if (str != NULL)
		free(str);
}
