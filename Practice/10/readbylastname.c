#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "student.h"

int main() {
	unsigned index;
	Student s;

	char lastname[20];
	printf("lastname: ");
	scanf("%s", lastname);

	int dFd = open(dbName, O_RDONLY, 0);

	while (read(dFd, &s, sizeof(Student))) {
		if (strcmp(s.lastname, lastname) == 0) {
			printf("id: %d\nfirstname: %s\nlastname: %s\nsemester: %d\n", s.id,
			       s.firstname, s.lastname, s.semester);
		}
	}

	return 0;
}
