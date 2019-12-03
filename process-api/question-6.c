#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	printf("Welcome aboard\n");
	int parent_pid = (int) getpid();
	int return_code = fork();
	if(return_code < 0) { //error
		fprintf(stderr, "forking error");
		exit(1);
	} else if(return_code == 0) { //child
		int status; // buffer to write return value into
		waitpid(parent_pid, &status, WUNTRACED|WCONTINUED);
		printf("I'm the child process\n");
	} else { //parent
		printf("I'm the parent process\n");
	}
	return 0;
}