#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("Please provide one argument\n");
	}

	unsigned int pid = fork();
	if (pid == 0) {
		printf("Child process\n");
		return execv(argv[1], &argv[1]);
	} else {
		int status;
		printf("Parent process. Child: %u\n", pid);
		wait(&status);
		printf("Child died. Child exit status: %d\n", status);
	}

	return 0;
}
