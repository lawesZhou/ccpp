#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "poisson.h"

static double exp_value(int i, double lambda)
{
	double pnum = 1.0;
	int j = 0;

	for (j = 1; j <= i; ++j) 
		pnum *= lambda / (double)j;

	return pnum / exp(lambda);
}

double *pois_value(int *n, void *param)
{
	double *lambda = (double *)param;

	int i = 0;
	double *ppois = malloc(sizeof(double));

	/*
	   p = e^(-lambda) * lambda ^ i / i!
	 */
	for (i = 0; i < *n; ++i) {
		if (i == 0)
			ppois[i] = 1 / exp(*lambda);
		else
			ppois[i] = ppois[i - 1] + exp_value(*lambda, i);

		if (ppois[i] < 1) {
			++(*n);
			ppois = realloc(ppois, (*n) * sizeof(double));
		}
	}	
	return ppois;
}

