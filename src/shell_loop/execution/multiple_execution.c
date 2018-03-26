/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Main file for all the "multiple execution" command (pipes)
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "instruction.h"

void multiple_execution(shell_t *shell, instruction_t *instruction)
{
	pid_t pid = 0;
	int **fd = malloc(sizeof(int *) * instruction->number_of_pipe);

	if (fd == NULL)
		exit(84);
	// finish fd malloc
	pid = fork();
	if (pid == -1)
		exit(84);
	if (pid == 0) {
		// fork again
		// si pid 0
			// fork again
			// si pid 0
				// exec, exit, dup
			// else
				// exec, dup, wait
		// else
			// exec, dup, wait
	} else {
		// wait main
	}
}
