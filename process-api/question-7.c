#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	printf("beam me up scotty\n");
	int return_code = fork();
	if(return_code < 0) {
		fprintf(stderr, "forking error");
		exit(1);
	} else if(return_code == 0) {
		close(STDOUT_FILENO);
		printf("Im going nowhere\n");
	} else {
		printf("I'm going somewhere\n");
	}
	return 0;
}