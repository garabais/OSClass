#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 10

sem_t mutexBuffer;
unsigned int buffer[BUF_SIZE];

sem_t semSpace, semData;

void *producer() {
	unsigned int curr = 0;

	while (1) {
		// Get data
		sleep(1);
		// Check for spaces
		sem_wait(&semSpace);
		// Check if the buffer is being used
		sem_wait(&mutexBuffer);
		// Modify the buffer
		buffer[curr++ % BUF_SIZE] = rand();
		// Unlock the buffer
		sem_post(&mutexBuffer);
		// Notify the client there's more data
		sem_post(&semData);
	}

	pthread_exit(NULL);
}

void *consumer() {
	unsigned int curr = 0;

	while (1) {
		// Check for data to process
		sem_wait(&semData);
		// Check if the buffer is being used
		sem_wait(&mutexBuffer);
		// Modify the buffer
		int data = buffer[curr++ % BUF_SIZE];
		// Unlock the buffer
		sem_post(&mutexBuffer);
		// Notify the client there's more space
		sem_post(&semSpace);
		// Data processing
		printf("The value read was %d\n", data);
		sleep(1);
	}

	pthread_exit(NULL);
}

int main() {
	// Initialize semaphores
	sem_init(&mutexBuffer, 0, 1);
	sem_init(&semSpace, 0, BUF_SIZE);
	sem_init(&semData, 0, 0);

	// Create threads
	pthread_t cons, prod;
	pthread_create(&cons, NULL, consumer, NULL);
	pthread_create(&prod, NULL, producer, NULL);

	// Wait for the threads to finish to exit the main thread
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);

	return 0;
}
