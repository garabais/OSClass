#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	unsigned index;
	Student s;

	printf("index: ");
	scanf("%d", &index);

	int dFd = open(dbName, O_RDWR, 0);
	lseek(dFd, sizeof(Student) * index, SEEK_SET);

	read(dFd, &s, sizeof(Student));

	char attribute[20];
	printf("attribute: ");
	scanf("%s", attribute);

	if (strcmp(attribute, "id") == 0) {
		printf("id: ");
		scanf("%d", &s.id);
	} else if (strcmp(attribute, "firstname") == 0) {
		printf("firstname: ");
		scanf("%s", s.firstname);
	} else if (strcmp(attribute, "lastname") == 0) {
		printf("lastname: ");
		scanf("%s", s.lastname);
	} else if (strcmp(attribute, "semester") == 0) {
		printf("semester: ");
		scanf("%d", &s.semester);
	} else {
		printf("invalid attribute\n");
		return 1;
	}

	lseek(dFd, sizeof(Student) * -1, SEEK_CUR);

	write(dFd, &s, sizeof(Student));

	close(dFd);

	return 0;
}
