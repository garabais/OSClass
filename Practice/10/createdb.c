#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int dFd = open(dbName, O_WRONLY | O_CREAT, 0644);
	Student* s = calloc(1, sizeof(Student));

	for (int i = 0; i < 20; i++) {
		write(dFd, s, sizeof(Student));
	}

	close(dFd);
	return 0;
}
