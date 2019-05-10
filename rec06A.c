/*	
	rec06A.c
	Recitation 6 - Zombies and Orphans
	Created by: Zachery Friedman - zmf0010
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
 
	pid_t pid;

	pid = fork();

	if(pid == 0){
	//CHILD
		exit(0);
	}
	else if(pid > 0) {
	//PARENT
		sleep(3);
		system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");
	}
	else {
		perror("fork error");
	}
}
