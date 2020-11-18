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
	printf("id: ");
	scanf("%d", &s.id);
	printf("firstname: ");
	scanf("%s", s.firstname);
	printf("lastname: ");
	scanf("%s", s.lastname);
	printf("semester: ");
	scanf("%d", &s.semester);

	int dFd = open(dbName, O_WRONLY, 0);

	lseek(dFd, sizeof(Student) * index, SEEK_SET);
	write(dFd, &s, sizeof(Student));
	close(dFd);

	return 0;
}
