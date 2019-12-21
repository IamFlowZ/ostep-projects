#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("hello world (pid: %d)\n", (int) getpid());
	int return_code = fork(); 
	if (return_code < 0) { // error
		fprintf(stderr, "fork failed\n"); 
		exit(1); 
	} else if (return_code == 0) { // child
		printf("hello from the child process, (pid: %d)\n", (int) getpid());
	} else { // parent
		int return_code_wait = wait(NULL);
		printf("I am %d and parent of %d. Did child succeed?: %s\n", (int) getpid(), return_code, return_code_wait > 0 ? "yes": "no");
	}
	return 0;
}