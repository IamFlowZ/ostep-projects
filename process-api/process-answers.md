1a.) Without changing the variable in either versions of the process it is unchanged it's initlization. <br>
1b.) The final value of the variable is determined by whichever process finishes last. <br>
2a.) Both the parent and the child processes have access to the file descriptior provided before the process fork took place. <br>
2b.) The parent process writes to the file first due to it having priority being the orignal process.<br>
3.) In my answer the parent will always run after the child has exited due to the added wait() call. Without that function call, there is the potential that the parent could exit before the child due to the process's exiting whenever the OS gets to them.<br>
4.) I believe there are numerous variations of exec in order to provide different means of interacting with spawned processes. Sometimes the program might provide feedback that the currently running program needs. Or it could be some sort of daemon, where we would want to the system to start the process and keep it running. Therefore the spawning process no longer needs any communication with that process.<br>
5a.) wait() returns either the completed process ID on success, or -1 on failure. <br>
5b.) If you call wait() in the child process, the child executes _after_ the parent process exits. <br>
6.) The waitpid() function is more suited when there is more than one sub-process being spawned. That way we avoid killing at random.<br>
7.) There is no longer a file descriptor for the stdout of the process. So the output is discarded. <br>
8.) 