#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int TOTAL_SEATS;
#define NUM_THREADS 15
#define OPERATIONS_PER_THREAD 50000
pthread_mutex_t lock;
printf("enter total seats : ");
scanf("%d",&TOTAL_SEATS);
int available_seats = TOTAL_SEATS;

void *booking_function(void *arg) {
    for (int i = 0; i < OPERATIONS_PER_THREAD; i++) {
        pthread_mutex_lock(&lock);
        if (available_seats > 0) {
            available_seats--;
            // printf("Thread %ld booked a ticket. Remaining seats: %d\n", (long)arg, available_seats);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *cancel_function(void *arg) {
    for (int i = 0; i < OPERATIONS_PER_THREAD; i++) {
        pthread_mutex_lock(&lock);
        if (available_seats < TOTAL_SEATS) {
            available_seats++;
            // printf("Thread %ld canceled a ticket. Remaining seats: %d\n", (long)arg, available_seats);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
   
    pthread_mutex_init(&lock, NULL);

    for (long i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, booking_function, (void *)i);
        } else {
            pthread_create(&threads[i], NULL, cancel_function, (void *)i);
        }
    }
   
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
   
    pthread_mutex_destroy(&lock);

    printf("Final number of available seats: %d\n", available_seats);
   
    return 0;
}
