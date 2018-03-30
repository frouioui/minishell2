/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** include file of the libmy functions
*/

#ifndef LIBMY_H
#define LIBMY_H

#include "shell.h"

int my_strlen(char *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_strcmp(char *str, char *str2);
char *get_next_line(int fd);
unsigned int my_number_row(char **array);
char *my_strcpy(char *dest, char *src);
char *my_get_env(char **env, char *target);
char **cut_line(char *line);
unsigned int get_line_env(char **env, char *target);
unsigned int get_line_env_zero(char **env, char *target);

#endif /* end of include guard: LIBMY_H */
