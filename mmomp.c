//Matrix Multiplication OMP
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>

#define H_A 11 // height of matrix A
#define W_A 11 // width of matrix A
#define H_B 11 // height of matrix B
#define W_B 11 // width of matrix B

int** matMul(int** A, int** B);

void printMatrix(int** matrix, size_t height, size_t width);
int** makeRandMatrix(size_t height, size_t width);

int main() {
	int** A = makeRandMatrix(H_A, W_A);
	int** B = makeRandMatrix(H_B, W_B);

	printf("\nMatrix A:\n");
	printMatrix(A, H_A, W_A);
	printf("\nMatrix B:\n");
	printMatrix(B, H_B, W_B);

	int** dotProduct = matMul(A, B);

	printf("\nDot Product A*B:\n");
	printMatrix(dotProduct, W_A, H_B);

	return 0;
}

int** matMul(int** A, int** B) {
	// if matrices are not compatible for multiplication, exit the program
	if (W_A != H_B) {
		printf("Matrices are not multiplicable. Exiting...\n");
		return  NULL;
	}

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

int** makeRandMatrix(size_t height, size_t width) {
	int** matrix = malloc(sizeof(int*) * height);

	for(size_t i = 0; i < width; i++) {
		matrix[i] = malloc(sizeof(int*) * width);
	}

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
            matrix[i][j] = rand() % 10;
		}
	}

	return matrix;
}
