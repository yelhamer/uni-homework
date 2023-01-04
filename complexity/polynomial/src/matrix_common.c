#include "../headers/matrix_common.h"


int **createMatrix(int n, int m, _Bool fill) {
	int **matrix = NULL;


	// Allocate memory space off the heap
	matrix = calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++) {
		matrix[i] = calloc(m, sizeof(int));
		if(fill)
			for(int j = 0; j < m; j++)
				matrix[i][j] = rand() % 200;
	}

	// Return the create matrix
	return matrix;
}


void printMatrix(int **matrix, int n, int m) {
	// Print the matrix' content seperated by lines and tabs
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			printf("%d\t", matrix[i][j]);
		
		printf("\n");
	}
}


void freeMatrix(int **matrix, int n) {
	// Free the matrix
	for(int i = 0; i < n; i++) 
		free(matrix[i]);
	
	free(matrix);
}
