#include <stdio.h>
#include <stdlib.h>

#include "gener.h"
#include "print.h"

static int binsearch(double *a, double val, int n)
{
	int start = 0;
	int last = n;
	int mid = (start + last) / 2;

	while (start <= last) {

  		if (val <= a[mid]) 
			last = mid - 1;

	       	if (val >= a[mid]) 
			start = mid + 1;

		mid = (start + last) / 2;
	}
	return start;
}

void gener_distri(int *distri, int N, double *(*quantile)(), void *parameters)
{
	int i;
	double randnum;
	int val = 0;
	int n = 1;

	double *distri_value = quantile(&n, parameters);

	printArray(distri_value, n);

	for (i = 0; i < N; ++i) {
		randnum = rand() / (double)RAND_MAX;
		val = binsearch(distri_value, randnum, n);
		printf("randnum = %lf, val = %d\n", randnum, val);

		++distri[val];
	}

	free(distri_value);
}
