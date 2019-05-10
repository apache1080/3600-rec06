/*	
	rec06B.c
	Recitation 6 - Zombies and Orphans
	Created by: Zachery Friedman - zmf0010
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	char *name;
	pid_t pid;
	int res;

	pid = fork();

	if(pid == 0) {
		printf("child:%d started\n", getpid());
		printf("child: parent = %d\n", getppid());
		printf("child:%d is going to sleep for 25 seconds...\n", getpid());
		sleep(25);
		printf("child:%d has woken up.\n", getpid());
	
		if(pid > 0) {
			printf("parent: %d started\n", getpid());
			printf("parent: parent = %d\n", getppid());
		}
		else {
			perror("fork error\n");
		}
	}
	else {
		perror("fork error\n");
	}

	name = (pid == 0) ? "child" : "parent";
	printf("%s: terminating...\n", name);

}
