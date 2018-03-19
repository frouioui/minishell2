/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** florent.poinsard@epitech.eu
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mylib.h"

Test(get_next_line_1, test_small_file)
{
	int fd = open("./tests/test_gnl_1", O_RDONLY);
	char tab[5][20] = {"salut", "comment", "ca va", "ici", "okay\tokay"};

	if (fd != 1) {
		for (int line = 0; line < 5; line++) {
			cr_assert_str_eq(get_next_line(fd), tab[line]);
		}
	}
}
