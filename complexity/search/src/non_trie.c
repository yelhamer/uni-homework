/* 
 * rechElets_TabNonTries: Check whether a given value exists or not within a given array
 * arr: array whithin which the search shall be performed
 * len: the length of the aforementioned array
 * x: the value to search for
 * RETURN: true if the value exists in the array, false otherwise
 *
 */
_Bool rechElets_TabNonTries(int *arr, int len, int x) {
	// Search the entire array for x
	int i = 0;
	while(i < len && arr[i] != x) 
		i++;
	
	// Return whether the search was halted because x was found
	return (i < len && arr[i] == x);
}
