/*
** EPITECH PROJET, 2018
** minishell2
** File description:
** Test file of the check_env_variable functions.
*/

#include <criterion/criterion.h>
#include "instruction.h"
#include "mylib.h"

Test(check_env_variable_1, check_1_variable)
{
	char **env = malloc(sizeof(char *) * 2);
	char **args = malloc(sizeof(char *) * 2);

	env[0] = my_strcpy(env[0], "HOME=/home/gildas");
	env[1] = my_strcpy(env[1], "TUTU=tata");
	args[0] = my_strcpy(args[0], "/bin/ls");
	args[1] = my_strcpy(args[1], "$HOME");
	check_env_variable(args, env);
	cr_assert_str_eq(args[0], "/bin/ls");
	cr_assert_str_eq(args[1], "/home/gildas");
}
