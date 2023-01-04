# ifndef __common_
#include "../headers/common.h"
# endif

// Used for qsort
_Bool compare_ints(int a, int b) {
	return a < b;
}


// Main
int main(int argc, char **argv) {
	int *array = NULL;
	int len = 0;
	int method_number = 0;


	// Check args
	if(argc != 3) {
		fprintf(stderr, "Usage: %s <array_length> <search_method>\narray_length: size of the array to be searched in.\narray_length:\n\t[0] non trie\n\t[1] trie\n\t[2] bisection\n", argv[0]);
		exit(1);
	}

	// Retrieve set array length and method number
	sscanf(argv[1], "%d", &len);
	sscanf(argv[2], "%d", &method_number);

	// Error Check
	// array length
	if(len <= 0) {
		perror("Non-positive array length");
		exit(1);
	}
	// method number
	if(method_number < 0 || method_number > 3) {
		perror("Method number must be 0, 1, or 2");
		exit(1);
	}

	// Fill the array with random values
	array = calloc(len, sizeof(int));
	srand(time(NULL));
	for(int i = 0; i < len; i++) {
		array[i] = rand();
	}


	// Measure execution time
	struct timeval tv;
	long int start, end;
	

	// Execute Search
	int x = array[rand() % len]; // search for a random element that's in the array
	switch(method_number) {
		case 0:
			// Start the counter then search
			gettimeofday(&tv, NULL);
			start = tv.tv_usec;
			rechElets_TabNonTries(array, len, x);
			
			break;

		case 1:
			// Sort
			qsort(array, len, sizeof(int), compare_ints);

			// Start counter then search
			gettimeofday(&tv, NULL);
			start = tv.tv_usec;
			rechElets_TabTries(array, len, x, 1);
			
			break;

		case 2:
			// Sort
			qsort(array, len, sizeof(int), compare_ints);

			// Start counter then search
			gettimeofday(&tv, NULL);
			start = tv.tv_usec;
			rechElets_Dicho(array, len, x, 1);
			
			break;

		default:
			break;
	}

	// Stop the counter
	gettimeofday(&tv, NULL);
	end = tv.tv_usec;
	
	// Print execution time
	printf("Execution time for size %d: %ld\n", len, end-start);


}
