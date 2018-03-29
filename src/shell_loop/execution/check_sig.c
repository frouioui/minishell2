/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Check if there was any signal in the child process
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "mylib.h"

static void core_dumped(int status)
{
	if (status == 11)
		my_putstr("Segmentation fault (core dumped)\n");
}

static void core_not_dumped(int status)
{
	if (status == 11)
		my_putstr("Segmentation fault\n");
}

void check_sig(int status)
{
	if (WIFSIGNALED(status)) {
		if (WCOREDUMP(status))
			core_dumped(status);
		else
			core_not_dumped(status);
	} else if (WIFSTOPPED(status)) {
		my_putstr("Stopped\n");
	}
}
