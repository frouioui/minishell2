/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Include file of the execution functions group
*/

#ifndef EXECUTION_H
#define EXECUTION_H

#include "shell.h"
#include "instruction.h"

unsigned int execute_command(shell_t *shell, command_line_t *command);
void multiple_execution(shell_t *shell, instruction_t *instruction);
unsigned int execute_command(shell_t *shell, command_line_t *command);

#endif /* end of include guard: EXECUTION_H */
