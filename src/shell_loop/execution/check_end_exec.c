/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Check the status variable that was sent to the exec function.
*/

#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "mylib.h"

void check_end_exec(int stat)
{
	if (WIFSIGNALED(stat)) {
		stat < 50 ? my_putstr(strsignal(stat)) : 0;
		stat > 50 ? my_putstr(strsignal(stat - 128)) : 0;
		my_putchar('\n');
	}
}
