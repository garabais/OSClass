#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 100

unsigned balance;
sem_t sem_balance;

void *addBalance(void *arg) {
	sem_wait(&sem_balance);
	unsigned initialValue = balance;
	unsigned finalValue = initialValue + 500;
	balance = finalValue;
	sem_post(&sem_balance);
	printf("The balance was %d, now is %d\n", initialValue, finalValue);
	pthread_exit(NULL);
}

int main() {
	balance = 0;
	sem_init(&sem_balance, 0, 1);

	pthread_t threads[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, addBalance, NULL);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("The final balance is %d\n", balance);
	return 0;
}
