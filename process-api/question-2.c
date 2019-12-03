#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("Hello there\n");
	int new_file = open("./output/quest-2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	int return_code = fork();
	if(return_code < 0) { // error
		fprintf(stderr, "forking error");
		exit(1);
	} else if(return_code == 0) { // child
		char child_val[6] = "child\n";
		int write_res = write(new_file, child_val, 6);
	} else { // parent
		char parent_val[7] = "parent\n";
		int write_res = write(new_file, parent_val, 7);
	}
	return 0;
}