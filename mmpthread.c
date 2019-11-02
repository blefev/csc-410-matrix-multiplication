//Matrix Multiplication Pthread
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// maximum size of matrix
#define MAX 10

// number of threads
#define NUM_THREAD 5

int matrixOne[MAX][MAX];
int matrixTwo[MAX][MAX];
int matrixThree[MAX][MAX];
int tmp = 0;

void* mult(void* arg)
{
    int core = tmp++;

    for (int i = core * MAX / 5; i < (core + 1) * MAX / 5; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                 matrixThree[i][j] += matrixOne[i][k] * matrixTwo[k][j];
}

int main()
{
    // Generating random values for matrixOne and matrixTwo
    for (int i = 0; i < MAX; i++)
     {
        for (int j = 0; j < MAX; j++)
        {
            matrixOne[i][j] = rand() % 10;
            matrixTwo[i][j] = rand() % 10;
        }
    }

    // print matrixOne
    printf("Matrix One: \n");
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d ", matrixOne[i][j]);
        }
        printf("\n");
    }
    // print matrixTwo
    printf("Matrix Two: \n");
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d ", matrixTwo[i][j]);
        }
        printf("\n");
    }

    // declaring threads
    pthread_t threads[NUM_THREAD];

    // creating threads
    for (int i = 0; i < NUM_THREAD; i++)
     {
        int* p;
        pthread_create(&threads[i], NULL, mult, (void*)(p));
    }

    // joining and waiting for all threads
    for (int i = 0; i < NUM_THREAD; i++)
        pthread_join(threads[i], NULL);

    // print matrixThree
    printf("Multiplied Matrix Result: \n");
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d ", matrixThree[i][j]);
        }
        printf("\n");
    }
    return 0;
}
   
