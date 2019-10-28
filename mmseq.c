//Matrix Multiplication Sequential


#include <stdio.h>
#include <stdlib.h>

void print(int **matrix, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int main(int argc, char *argv[])
{

	int max = atoi(argv[1]);
	int seed = atoi(argv[2]);
	int size = atoi(argv[3]);

	srand(seed);

	int **matrixOne = (int **) malloc(sizeof(int *) * size);
	int **matrixTwo = (int **) malloc(sizeof(int *) * size);
	int **matrixThree = (int **) malloc(sizeof(int *) * size);

	for (int i = 0; i < size; ++i)
	{
		 matrixOne[i] = (int *) malloc(sizeof(int) * size);
		 matrixTwo[i] = (int *) malloc(sizeof(int) * size);
		 matrixThree[i] = (int *) malloc(sizeof(int) * size);
	}

	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			 matrixOne[i][j] = (rand() % max + 1);
			 matrixTwo[i][j] = (rand() % max + 1);
			 matrixThree[i][j] = 0;
		}
	}

	printf("Matrix One: \n");
	print(matrixOne, size);

	printf("Matrix Two: \n");
	print(matrixTwo, size);

	printf("Performing Matrix Multiplication \n");

	for (int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			for(int k = 0; k < size; ++k)
			{
				matrixThree[i][j] += matrixOne[i][k] * matrixTwo[k][j];
			}
		}

	}

	printf("Multiplied Matrix Result: \n");
	print(matrixThree, size);

	return 0;
}
