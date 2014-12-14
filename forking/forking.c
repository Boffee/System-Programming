#include <unistd.h> /* standard symbolic constants and types */
#include <stdio.h> /* standard inputs and outputs */
#include <stdlib.h> /* standart library for general functions */

int main() {
	int answer = 6 << 1; /* bitsift */
	// print answer and flush the buffer with newline
	printf("answer: %d\n", answer); 
	pid_t id = fork(); /* id of fork */
	if (id == -1) exit(1); /*fork failed */
	if (id > 0) {
		// this is the original parent id
		int status;
		waitpid(id, &status, 0);
		printf("original parent process with id: %d", id);
		return EXIT_SUCCESS;
	} else {
		// this is the fork
		pid_t ppid = getppid();
		printf("child process with parent id %d\n", ppid);
	}
	return 0;
}