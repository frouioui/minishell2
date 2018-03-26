/*
** EPITECH PROJET, 2018
** project
** File description:
** pflorent
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>

char **seg_line(char *line);

int main(int argc, char **argv, char **env)
{
	int status = 0;
	int pipe_1[2] = {0};
	int pipe_2[2] = {0};
	char **args1 = seg_line("/bin/ls /dev");
	char **args2 = seg_line("/bin/grep tty");
	char **args3 = seg_line("/bin/more");
	int nb_inst = 3;
	int pid = 0;
	int pid_2 = 0;

	if pipe(fds) == -1
		perror("pipe");
	if ((pid = fork()) == -1)
		perror("fork");
	if (pid == 0) {
		dup2(pipe_1[1], 1);
		execve(args[0], args1, env);
		close(pipe_1[1]);
		exit(0);
	} else {
		dup2(pipe_1[0], 0);
		execve(args3[0], args3, env);
		wait(NULL);
		close(pipe_1[0]);
	}
	return (0);
}
