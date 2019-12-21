#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int file_descriptor[2], child_rc;
	char string[] = "\"something clever\"\n";
	char read_buffer[100];

	pipe(file_descriptor);
	child_rc = fork();
	if(child_rc < 0) { // error
		fprintf(stderr, "forking error");
		exit(1);
	} else if(child_rc == 0) { // child
		close(file_descriptor[0]); // closing pipe input
		write(file_descriptor[1], string, (strlen(string) + 1)); // writing output to be read in
		exit(0);
	} else { // parent
		close(file_descriptor[1]); // closing pipe output
		read(file_descriptor[0], read_buffer, sizeof(read_buffer)); // reading input string from child
		printf("Recieved: %sfrom child process.\n", read_buffer);
	}

	return 0;
}