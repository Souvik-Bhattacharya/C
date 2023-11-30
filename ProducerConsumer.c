#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

// Structure to represent the shared buffer
struct SharedBuffer {
    int buffer[BUFFER_SIZE];
    int in; // Index to insert item (producer)
    int out; // Index to remove item (consumer)
    sem_t mutex; // Semaphore for mutual exclusion
    sem_t empty; // Semaphore to indicate available space in buffer
    sem_t full;  // Semaphore to indicate available data in buffer
};

// Function prototypes
void initBuffer(struct SharedBuffer *buffer);
void produce(struct SharedBuffer *buffer, int item);
int consume(struct SharedBuffer *buffer);

// Thread function prototypes
void *producer(void *arg);
void *consumer(void *arg);

int main() {
    pthread_t producerThread, consumerThread;
    struct SharedBuffer sharedBuffer;

    // Initialize shared buffer
    initBuffer(&sharedBuffer);

    // Create threads for producer and consumer
    if (pthread_create(&producerThread, NULL, producer, &sharedBuffer) != 0 ||
        pthread_create(&consumerThread, NULL, consumer, &sharedBuffer) != 0) {
        perror("Error creating threads");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    if (pthread_join(producerThread, NULL) != 0 || pthread_join(consumerThread, NULL) != 0) {
        perror("Error joining threads");
        exit(EXIT_FAILURE);
    }

    // Destroy semaphores
    sem_destroy(&sharedBuffer.mutex);
    sem_destroy(&sharedBuffer.empty);
    sem_destroy(&sharedBuffer.full);

    return 0;
}

void initBuffer(struct SharedBuffer *buffer) {
    buffer->in = 0;
    buffer->out = 0;

    // Initialize semaphores
    sem_init(&buffer->mutex, 0, 1);   // Initial value of mutex semaphore is 1 (unlocked)
    sem_init(&buffer->empty, 0, BUFFER_SIZE); // Initial value of empty semaphore is BUFFER_SIZE
    sem_init(&buffer->full, 0, 0);   // Initial value of full semaphore is 0
}

void produce(struct SharedBuffer *buffer, int item) {
    // Wait for available space in buffer
    sem_wait(&buffer->empty);

    // Use mutex for mutual exclusion
    sem_wait(&buffer->mutex);

    // Produce item and add to buffer
    buffer->buffer[buffer->in] = item;
    buffer->in = (buffer->in + 1) % BUFFER_SIZE;

    printf("Produced item %d\n", item);

    // Signal the full semaphore to indicate available data in buffer
    sem_post(&buffer->full);

    // Release mutex
    sem_post(&buffer->mutex);
}

int consume(struct SharedBuffer *buffer) {
    int item;

    // Wait for available data in buffer
    sem_wait(&buffer->full);

    // Use mutex for mutual exclusion
    sem_wait(&buffer->mutex);

    // Remove item from buffer and consume
    item = buffer->buffer[buffer->out];
    buffer->out = (buffer->out + 1) % BUFFER_SIZE;

    printf("Consumed item %d\n", item);

    // Signal the empty semaphore to indicate available space in buffer
    sem_post(&buffer->empty);

    // Release mutex
    sem_post(&buffer->mutex);

    return item;
}

void *producer(void *arg) {
    struct SharedBuffer *buffer = (struct SharedBuffer *)arg;

    for (int i = 1; i <= 10; ++i) {
        // Produce item
        produce(buffer, i);

        // Sleep for a random time to simulate variable production time
        usleep(rand() % 500000); // Sleep for up to 0.5 seconds
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    struct SharedBuffer *buffer = (struct SharedBuffer *)arg;

    for (int i = 0; i < 10; ++i) {
        // Consume item
        consume(buffer);

        // Sleep for a random time to simulate variable consumption time
        usleep(rand() % 500000); // Sleep for up to 0.5 seconds
    }

    pthread_exit(NULL);
}
