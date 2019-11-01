//Matrix Multiplication OMP
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>
#define H_A 11
#define W_A 11
#define H_B 11
#define W_B 11

int** matMul(int A[H_A][W_A] , int B[H_B][W_A] );

void  printMatrix(int** matrix, size_t height, size_t width);

int main() {
	int A[H_A][W_A]  = {
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
	};

	int B[H_B][W_B]  = {
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
		{84, 12, 15, 88, 15,84, 15, 320, 15, 384, 15},
		{10, 53, 85, 1, 5, 83, 84, 32, 842, 94, 92},
	};

	int** dotProduct = matMul(A, B);

	printMatrix(dotProduct, W_A, H_B);

	return 0;
}

int** matMul(int A[H_A][W_A] , int B[H_B][W_A] ) {
	// if matrices are not compatible for multiplication, exit the program
	if (W_A != H_B) {
		printf("Matrices are not multiplicable. Exiting...\n");
		return  NULL;
	}

	// create a vector with rows = a rows, cols = b cols
	//int C[W_A][H_B];
	int** C = malloc(sizeof(int*) * W_A);

    for(size_t i = 0; i < W_A; i++) {
        C[i] = malloc(sizeof(int*) * H_B);
    }
	// go through each row
	#pragma omp parallel for schedule(static, 1)
	for (size_t i = 0; i < H_A; i++) {
		// go through each column
		for (size_t j = 0; j < W_B; j++) {
			int sum = 0;

			// calculate products and sums for dot product
			for (size_t k = 0; k < H_B; k++) {
				usleep(5000);
				sum += A[i][k] * B[k][j];
				C[i][j] = sum;
			}
		}
	}
	return C;
}

void  printMatrix(int** matrix, size_t height, size_t width) {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			printf("%d ", matrix[i][j]);	
		}
		printf("\n");
	}
}
