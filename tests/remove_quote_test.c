/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** Test the remove quote function.
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "mylib.h"

Test(remove_quote, simple_string)
{
	char **args = malloc(sizeof(char *) * 5);

	args[0] = my_strcpy(NULL, "test");
	args[1] = my_strcpy(NULL, "simple");
	args[2] = my_strcpy(NULL, "okay");
	args[3] = my_strcpy(NULL, "salut salut");
	args[4] = NULL;
	remove_quote(args);
	cr_assert_str_eq(args[0], "test");
	cr_assert_str_eq(args[1], "simple");
	cr_assert_str_eq(args[2], "okay");
	cr_assert_str_eq(args[3], "salut salut");
}

Test(remove_quote, quoted_string)
{
	char **args = malloc(sizeof(char *) * 5);

	args[0] = my_strcpy(NULL, "\"test\"");
	args[1] = my_strcpy(NULL, "\"simple\"");
	args[2] = my_strcpy(NULL, "\"okay\"");
	args[3] = my_strcpy(NULL, "\"salut salut\"");
	args[4] = NULL;
	remove_quote(args);
	cr_assert_str_eq(args[0], "test");
	cr_assert_str_eq(args[1], "simple");
	cr_assert_str_eq(args[2], "okay");
	cr_assert_str_eq(args[3], "salut salut");
}
