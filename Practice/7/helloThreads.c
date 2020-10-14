#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct td {
	int hid;
	char *msg;
} ThreadData;

// Compile and link with ptread
void *hello(void *data) {
  ThreadData *td = (ThreadData *)data;
  printf("%s %d\n", td->msg, td->hid);
  free(data);
  pthread_exit(NULL);
}

int main() {
	pthread_t newThread;
	for (int i = 0; i < 10; i++) {
		ThreadData *td = (ThreadData *)malloc(sizeof(ThreadData));
		td->msg = "Hello Thread";
		td->hid = i;
		pthread_create(&newThread, NULL, hello, (void *)td);
	}
	pthread_exit(NULL);
}
