/* 
 * rechElets_TabTries: Check whether a given value exists or not within a given sorted array
 * arr: array whithin which the search shall be performed
 * len: the length of the aforementioned array
 * asc_order: true if the array is sorted in ascending order, false otherwise
 * x: the value to search for
 * RETURN: true if the value exists, false otherwise
 *
 */

_Bool rechElets_TabTries(int *arr, int len, _Bool asc_order, int x) {
	// Search the array until x is found or a larger value is encountered
	int i = 0;
	while(i < len &&
	asc_order ? arr[i] < x : arr[i] > x) {	
		i++;
	}

	// Return whether the current element the search halted at is equal to x
	return (i < len && arr[i] == x);
}


/* 
 * rechElets_TabTries: Check whether a given value exists or not within a given sorted array
 * arr: array whithin which the search shall be performed
 * len: the length of the aforementioned array
 * asc_order: true if the array is sorted in ascending order, false otherwise
 * x: the value to search for
 * RETURN: true if the value exists, false otherwise
 *
 */

_Bool rechElets_Dicho(int *arr, int len, int x, _Bool asc_order) {
	int start = 0;
	int end = len-1;
	int distance = end-start;
	
	// Bisection Algorithm
	while(start < end && arr[start+distance/2] != x) {
		if(asc_order) {
			start = arr[start+distance/2] < x ? start+distance/2 : start;
			end = arr[start+distance/2] > x ? start+distance/2 : end;

		} else {
			start = arr[start+distance/2] > x ? start+distance/2 : start;
			end = arr[start+distance/2] < x ? start+distance/2 : end;

		}

		distance = end-start;
	}

	// Return whether the current array element equals x
	return(arr[start+distance/2] == x);

	
}
