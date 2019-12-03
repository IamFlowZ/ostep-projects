#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("hello there\n");
	int x = 0;
	int return_code = fork();
	if(return_code < 0) { //error
		fprintf(stderr, "failed to create child\n");
	} else if(return_code == 0) { // child
		x = 250;
		printf("x from the child is %d\n", x);
	} else { // parent
		int rc_wait = wait(NULL);
		x = 999;
		printf("x from the parent is %d\n", x);
	}
	printf("final x: %d\n", x);
	return 0;
}