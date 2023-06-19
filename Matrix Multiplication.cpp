#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100
#define NUM_THREADS 4

int matrixA[SIZE][SIZE];
int matrixB[SIZE][SIZE];
int result[SIZE][SIZE];

struct ThreadData {
    int start;
    int end;
};

void *multiply(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;

    for (int i = data->start; i < data->end; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    // Initialize matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrixA[i][j] = i + j;
            matrixB[i][j] = i - j;
        }
    }

    // Calculate the range of rows each thread will handle
    int chunkSize = SIZE / NUM_THREADS;
    int remainingRows = SIZE % NUM_THREADS;
    int start = 0;

    // Create threads and assign work
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].start = start;
        threadData[i].end = start + chunkSize;

        if (remainingRows > 0) {
            threadData[i].end++;
            remainingRows--;
        }

        pthread_create(&threads[i], NULL, multiply, (void *)&threadData[i]);

        start = threadData[i].end;
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Compute the final sum
    int finalSum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            finalSum += result[i][j];
        }
    }

    printf("Final Sum: %d\n", finalSum);

    return 0;
}

