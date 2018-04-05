/*
** EPITECH PROJECT, 2018
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
	int pipe_1[2];
	int pipe_2[2];
	char **args1 = seg_line("/bin/ls /dev -l");
	char **args2 = seg_line("/bin/grep tty");
	char **args3 = seg_line("/bin/more");
	int nb_inst = 3;
	int pid = 0;
	int pid_2 = 0;

	if (pipe(pipe_1) == -1)
		perror("pipe");
	if (pipe(pipe_2) == -1)
		perror("pipe");
	if ((pid = fork()) == -1)
		perror("fork");
	if (pid == 0) {
		printf("pid = %d\n", pid);
		pid_2 = fork();
		if (pid_2 == -1)
			perror("fork");
		if (pid_2 == 0) {
			close(pipe_2[0]);
			dup2(pipe_2[1], 1);
			execve(args1[0], args1, env);
			exit(0);
		} else {
			printf("%d\n", pid_2);
			printf("end wait grep\n");
			close(pipe_2[1]);
			close(pipe_1[0]);
			dup2(pipe_2[0], 0);
			dup2(pipe_1[1], 1);
			execve(args2[0], args2, env);
			exit(0);
		}
	} else {
		printf("begin wait\n");
		printf("end wait parent\n");
		close(pipe_1[1]);
		dup2(pipe_1[0], 0);
		execve(args3[0], args3, env);
		close(pipe_1[0]);
	}
	return (0);
}
