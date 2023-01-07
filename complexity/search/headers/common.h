#define __common_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

struct _exVals {
	int min;
	int max;
	int cpt; // A counter for the number of comparisons
};

typedef struct _exVals exVals_t;

// Function signatures
_Bool rechElets_TabNonTries(int *, int, int);
_Bool rechElets_TabTries(int *, int, _Bool, int );
_Bool rechElets_Dicho(int *, int, int, _Bool);
exVals_t MinEtMaxA(int *a, int);
exVals_t MinEtMaxB(int *a, int);
