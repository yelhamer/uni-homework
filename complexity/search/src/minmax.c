#include "../headers/common.h"

/*
 * MinEtMaxA: Find the minimum and maximum following the first algorithm
 * arr: Array to search in
 * len: length of the array
 * RETURN: a struct _exVals containing the minimum and maximum
 */
exVals_t MinEtMaxA(int *arr, int len) {
	exVals_t mm;

	// Initialize to the first element
	mm.min = mm.max = arr[0];
	mm.cpt = 0;

	// Find minimum and maximum
	for(int i = 1; i < len; i++) {
		if(mm.min > arr[i])
			mm.min = arr[i];

		if(mm.max < arr[i])
			mm.max = arr[i];

		mm.cpt += 2;
	}

	// Return the minimum and maximum
	return mm;
}


/*
 * MinEtMaxB: Find the minimum and maximum following the second algorithm
 * arr: Array to search in
 * len: length of the array
 * RETURN: a struct _exVals containing the minimum and maximum
 */
exVals_t MinEtMaxB(int *arr, int len) {
	exVals_t mm;
	int temp;
	
	// Initialize to the first element
	mm.min = mm.max = arr[0];
	mm.cpt = 0;

	// Partition elements
	for(int i = 0; i < (len & !1) ; i+=2) {
		if(arr[i] > arr[i+1]) {
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}

		mm.cpt++;
	}

	// Find minimum and maximum
	for(int i = 0; i < len; i++) {
		if(i%2) {
			// odd
			if(mm.max < arr[i])
				mm.max = arr[i];
		} else {
			// even
			if(mm.min > arr[i])
				mm.min = arr[i];
		}

		mm.cpt++;
	}

	// Necessary if the array has an odd number of elements
	if(mm.max < arr[len-1])
		mm.max = arr[len-1];
	if(mm.min > arr[len-1])
		mm.min = arr[len-1];

	mm.cpt += 2;

	// Return the minimum and maximum
	return mm;
}
