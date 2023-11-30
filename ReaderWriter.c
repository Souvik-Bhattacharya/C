#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define READERS_COUNT 5
#define WRITERS_COUNT 3

// Structure to represent shared data
struct SharedData {
    int data;
    int readersCount;
    sem_t mutex;        // Semaphore for mutual exclusion
    sem_t readersMutex; // Semaphore for controlling access by readers
    sem_t writersMutex; // Semaphore for controlling access by writers
};

// Function prototypes
void initSharedData(struct SharedData *sharedData);
void readData(struct SharedData *sharedData, int readerId);
void writeData(struct SharedData *sharedData, int writerId);

// Thread function prototypes
void *reader(void *arg);
void *writer(void *arg);

int main() {
    pthread_t readers[READERS_COUNT], writers[WRITERS_COUNT];
    struct SharedData sharedData;

    // Initialize shared data
    initSharedData(&sharedData);

    // Create threads for readers and writers
    for (int i = 0; i < READERS_COUNT; ++i) {
        if (pthread_create(&readers[i], NULL, reader, &sharedData) != 0) {
            perror("Error creating reader threads");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < WRITERS_COUNT; ++i) {
        if (pthread_create(&writers[i], NULL, writer, &sharedData) != 0) {
            perror("Error creating writer threads");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all reader and writer threads to finish
    for (int i = 0; i < READERS_COUNT; ++i) {
        if (pthread_join(readers[i], NULL) != 0) {
            perror("Error joining reader threads");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < WRITERS_COUNT; ++i) {
        if (pthread_join(writers[i], NULL) != 0) {
            perror("Error joining writer threads");
            exit(EXIT_FAILURE);
        }
    }

    // Destroy semaphores
    sem_destroy(&sharedData.mutex);
    sem_destroy(&sharedData.readersMutex);
    sem_destroy(&sharedData.writersMutex);

    return 0;
}

void initSharedData(struct SharedData *sharedData) {
    sharedData->data = 0;
    sharedData->readersCount = 0;

    // Initialize semaphores
    sem_init(&sharedData->mutex, 0, 1);         // Initial value of mutex semaphore is 1 (unlocked)
    sem_init(&sharedData->readersMutex, 0, 1);  // Initial value of readersMutex semaphore is 1
    sem_init(&sharedData->writersMutex, 0, 1);  // Initial value of writersMutex semaphore is 1
}

void readData(struct SharedData *sharedData, int readerId) {
    // Wait for access to readersCount
    sem_wait(&sharedData->readersMutex);

    // Increment readersCount
    sharedData->readersCount++;

    // If it's the first reader, wait for access to the writers
    if (sharedData->readersCount == 1) {
        sem_wait(&sharedData->writersMutex);
    }

    // Release access to readersCount
    sem_post(&sharedData->readersMutex);

    // Read data
    printf("Reader %d reads data: %d\n", readerId, sharedData->data);

    // Wait for access to readersCount
    sem_wait(&sharedData->readersMutex);

    // Decrement readersCount
    sharedData->readersCount--;

    // If it's the last reader, release access to the writers
    if (sharedData->readersCount == 0) {
        sem_post(&sharedData->writersMutex);
    }

    // Release access to readersCount
    sem_post(&sharedData->readersMutex);
}

void writeData(struct SharedData *sharedData, int writerId) {
    // Wait for access to writers
    sem_wait(&sharedData->writersMutex);

    // Write data
    sharedData->data++;
    printf("Writer %d writes data: %d\n", writerId, sharedData->data);

    // Release access to writers
    sem_post(&sharedData->writersMutex);
}

void *reader(void *arg) {
    struct SharedData *sharedData = (struct SharedData *)arg;
    int readerId = rand() % 1000; // Unique identifier for the reader

    while (1) {
        usleep(rand() % 500000); // Sleep for up to 0.5 seconds
        readData(sharedData, readerId);
    }

    pthread_exit(NULL);
}

void *writer(void *arg) {
    struct SharedData *sharedData = (struct SharedData *)arg;
    int writerId = rand() % 1000; // Unique identifier for the writer

    while (1) {
        usleep(rand() % 500000); // Sleep for up to 0.5 seconds
        writeData(sharedData, writerId);
    }

    pthread_exit(NULL);
}
