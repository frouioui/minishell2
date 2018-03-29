/*
** EPITECH PROJECT, 2018
** project
** File description:
** pflorent
*/

#include "shell.h"
#include "instruction.h"
#include "execution.h"

void simple_execution(shell_t *shell, instruction_t *instruction)
{
	printf("simple execution of %s\n", instruction->pipe[0]->args[0]);
}
