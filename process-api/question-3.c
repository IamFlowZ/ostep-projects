#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	printf("Hello there\n");
	int return_code = fork();
	if(return_code < 0) { // error
		fprintf(stderr, "forking error");
		exit(1);
	} else if (return_code == 0) { // child
		printf("Hello from the child.\n");
	} else { // parent
		int return_wait = wait(NULL);
		printf("Goodbye from the parent.\n");
	}
	return 0;
}