/*
** EPITECH PROJECT, 2018
** project
** File description:
** pflorent
*/

#include "mylib.h"

void display_error_execution(char *filename)
{
	my_putstr(filename);
	my_putstr(": Command not found.\n");
}
