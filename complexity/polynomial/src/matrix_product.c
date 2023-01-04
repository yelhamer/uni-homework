#include "../headers/matrix_common.h"
#include <sys/time.h>


int main(int argc, char **argv) {
	// Dimension variables
	int n, m, p;

	// Check calling syntax
	if(argc != 4) {
		fprintf(stderr, "Usage: ./%s n m p\n", argv[0]);
		exit(1);
	}

	// Get args
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m);
	sscanf(argv[3], "%d", &p);


	// Check dimensions
	if(n < 0 || m < 0 || p < 0) {
		perror("Incorrect dimensions.");
		exit(1);
	}


	// Declare matrices to be used as well as the timer
	int **A = NULL;
	int **B = NULL;
	int **C = NULL;
	struct timeval tv;
	long int start;

	// Allocate memory space for matrices off the heap
	A = createMatrix(n, m, 1);
	B = createMatrix(m, p, 1);
	C = createMatrix(n, p, 0);

	// Initialize the timer
	gettimeofday(&tv, NULL);
	start = tv.tv_usec;

	// Multiplication
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < p; j++) {
			C[i][j] = 0;
			for(int k = 0; k < m; k++) 
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	
	// Stop the timer
	gettimeofday(&tv, NULL);

	// Print execution time
	printf("Execution time: %ld\n", tv.tv_usec - start);

	// Print A, B, andresult matrices
	printf("\nMatrix A:\n");
	printMatrix(A, n, m);
	
	printf("\nMatrix B:\n");
	printMatrix(B, m, p);
	
	printf("\nMatrix C:\n");
	printMatrix(C, n, p);

	// Free matrices' allocated memory space
	freeMatrix(A, n);
	freeMatrix(B, m);
	freeMatrix(C, n);

	return 0;
}
