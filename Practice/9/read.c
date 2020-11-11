#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd = open("./Makefile", O_RDONLY, 0);

	if (fd < 0) {
		printf("Error opening file\n");
		return 1;
	}

	char c;

	while (read(fd, &c, 1)) {
		printf("%c", c);
	}

	close(fd);

	return 0;
}
