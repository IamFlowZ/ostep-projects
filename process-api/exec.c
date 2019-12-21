#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("hello there, (pid: %d)\n", (int) getpid());
	int return_code = fork();
	if(return_code < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(1);
	} else if(return_code == 0) { // child
		printf("I am the child process (pid: %d)\n", (int) getpid());
		close(STDOUT_FILENO);
		open("./my-exec.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("exec.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		printf("this shouldn't print out\n");
	} else { // parent
		int return_code_wait = wait(NULL);
		printf("I am %d and parent of %d. Did child succeed?: %s\n", (int) getpid(), return_code, return_code_wait > 0 ? "yes": "no");
	}
	return 0;
}