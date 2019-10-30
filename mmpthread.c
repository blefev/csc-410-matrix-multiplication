//Matrix Multiplication Pthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAT 5

void *matmul(void* arg)
{
    int *nums = (int *)arg;
    int i = 0;
    int j = 0;

    int tmp = nums[0];
    for(i = 1; i <= tmp; i++)

        j += nums[i]*nums[i+tmp];
        int *p = (int*)malloc(sizeof(int));
        *p = j;
        // terminate thread return pointer
        pthread_exit(p);

}//end matmul

int main()
{
    int matrixOne[MAT][MAT];
    int matrixTwo[MAT][MAT];

    int row1 = MAT;
    int col1 = MAT;
    int row2 = MAT;
    int col2 = MAT;

    int i, j, k;

    // generate rand values for matrixOne
    for(i = 0; i < row1; i++)

        for(j = 0; j < col1; j++)

            matrixOne[i][j] = rand() % 10;
// generate rand values for matrixTwo
    for(i = 0; i < row1; i++)

        for(j = 0; j < col1; j++)

            matrixTwo[i][j] = rand() % 10;



    // print  matrixOne
    printf("Matrix One: \n");
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col1; j++)
            printf("%d ", matrixOne[i][j]);
            printf("\n");
    }

    // print  matrixTwo
    printf("Matrix Two: \n");
    for(i = 0; i < row2; i++)
    {
        for(j = 0; j < col2; j++)
            printf("%d ", matrixTwo[i][j]);
            printf("\n");
    }

    int tar = row1*col2;
    // declaring threads
    pthread_t *threads;
    threads = (pthread_t*)malloc(tar*sizeof(pthread_t));

    int count = 0;
    int* nums = NULL;

    for(i = 0; i < row1; i++)

        for(j = 0; j < col2; j++)
        {
            nums = (int *)malloc((1000)*sizeof(int));
            nums[0] = col1;

            for(k = 0; k < col1; k++)

                nums[k+1] = matrixOne[i][k];

            for(k = 0; k < row2; k++)

                nums[k+col1+1] = matrixTwo[k][j];

            // creating threads
            pthread_create(&threads[count++], NULL, matmul, (void*)(nums));

        }

    printf("Multiplied Matrix Result: \n");
    for(i = 0; i < tar; i++)
    {
        void *k;
        // joining the threads
        pthread_join(threads[i], &k);

        int *p = (int *)k;
        printf("%d ", *p);
        if((i + 1) % col2 == 0)
            printf("\n");
    }
    return 0;
}//end main
