#include <pthread.h> 

#include <stdio.h> 

#include <stdlib.h> 

 

#define NUM_THREADS 5 

#define NUM_INCREMENTS 100000 

 

pthread_mutex_t mutex; 

int counter = 0; 

 

void *increment_counter(void *arg) { 

    for (int i = 0; i < NUM_INCREMENTS; i++) { 

        pthread_mutex_lock(&mutex); 

        counter++; 

        pthread_mutex_unlock(&mutex); 

    } 

    return NULL; 

} 

 

int main() { 

    pthread_t threads[NUM_THREADS]; 

 

    // Initialize the mutex 

    pthread_mutex_init(&mutex, NULL); 

 

    // Create threads 

    for (int i = 0; i < NUM_THREADS; i++) { 

        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) { 

            perror("Failed to create thread"); 

            return 1; 

        } 

    } 

 

    // Join threads 

    for (int i = 0; i < NUM_THREADS; i++) { 

        pthread_join(threads[i], NULL); 

    } 

 

    // Destroy the mutex 

    pthread_mutex_destroy(&mutex); 

 

    printf("Final counter value: %d\n", counter); 

    return 0; 

} 
