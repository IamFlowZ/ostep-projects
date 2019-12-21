#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	printf("Starting up...\n");
	int return_code = fork();
	if (return_code < 0) { // error
		fprintf(stderr, "forking error.\n");
		exit(1);
	} else if(return_code == 0) { // child
		char* new_args[3];
		new_args[0] = strdup("ls");
		new_args[1] = strdup("output");
		new_args[2] = NULL;
		execvp(new_args[0], new_args);
	} else { // parent
		wait(NULL);
		printf("Im the parent\n");
	}
	return 0;
}