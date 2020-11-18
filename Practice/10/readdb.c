#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	unsigned index;
	Student s;

	printf("index: ");
	scanf("%d", &index);

	int dFd = open(dbName, O_RDONLY, 0);
	lseek(dFd, sizeof(Student) * index, SEEK_SET);

	read(dFd, &s, sizeof(Student));

	printf("id: %d\nfirstname: %s\nlastname: %s\nsemester: %d\n", s.id,s.firstname,s.lastname,s.semester);

	return 0;
}
