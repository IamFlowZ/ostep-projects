#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/wait.h>

/**
 * printError - Standard error message
 **/
void printError() {
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
}

/**
 * cd - Changes current working directory
 **/
int cd(char *path) {
    char cwd[PATH_MAX];
    if(chdir(path) != 0) {
        printError();
        return 1;
    } else if(getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Switched to: %s\n", cwd);
        return 0;
    } else {
        printError();
        return 1;
    }
}

/**
 * path - adds space delimited directories to the current evironments PATH variable
 **/
int path() {
    printf("path\n");
    return 0;
}

/**
 * splitString - splits original string on spaces into the provided buffer
 **/
void splitString(char** buf, char* original) {
    int i = 0;
    char * token;
    while((token = strsep(&original, " ")) != NULL) {
        buf[i] = strdup(token);
        i++;
    }
    buf[i] = NULL;
}

int main(int argc, char *argv[]) {
    while(1) {
        printf("wish> ");
        char *readBuf = NULL; 
        char *splitBuf[10];
        size_t len = 0;
        ssize_t chars = getline(&readBuf, &len, stdin);
        if(readBuf[chars - 1] == '\n')
            readBuf[chars - 1] = '\0';
        splitString(splitBuf, readBuf);
        int return_code = fork(); 
        if (return_code < 0) { // error
            printError();
            exit(1); 
        } else if (return_code == 0) { // child
            if(strcmp(splitBuf[0], "cd") == 0) {
                cd(splitBuf[1]);
            } else if(strcmp(splitBuf[0], "path") == 0) {
                path();
            } else if(strcmp(splitBuf[0], "exit") == 0) {
                exit(0);
            } else {
                if(execv(splitBuf[0], splitBuf))
                    printError();
            }
        } else { // parent
            wait(NULL);
            exit(0);
        }
    }
    return 0;
}