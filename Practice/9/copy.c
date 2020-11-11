#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Invalid number of arguments\n");
		return 2;
	}

	int fdo = open(argv[1], O_RDONLY, 0);

	if (fdo < 0) {
		printf("Error opening origin file\n");
		return 1;
	}

	int fdd = open(argv[2], O_WRONLY | O_CREAT, 0644);

	if (fdo < 0) {
		printf("Error opening destination file\n");
		return 1;
	}

	char c;

	while (read(fdo, &c, 1)) {
		write(fdd, &c, 1);
	}

	close(fdo);
	close(fdd);

	return 0;
}
