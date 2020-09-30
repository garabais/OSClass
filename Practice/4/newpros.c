#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void sighandler(int signum) {
	// Wait the child process and catch the status
	int status;
	wait(&status);
	// Inform that the child died and inform the status
	printf("Child died. Child exit status: %d\n", status);
}

int main(int argc, char* argv[]) {

	// Catch the sigchl
	signal(17, sighandler);

	// Check number of arguments
	if (argc < 2) {
		printf("Please provide one argument\n");
	}

	// Create new process
	unsigned int pid = fork();
	if (pid == 0) {
		printf("Child process\n");
		// execute the program passed by args in the child
		return execv(argv[1], &argv[1]);
	} else {
		printf("Parent process. Child: %u\n", pid);

		// Continue doing some stuff in the parent proccess
		while (1) {
			sleep(2);
			printf("Doing some things\n");
		}

	}

	return 0;
}
