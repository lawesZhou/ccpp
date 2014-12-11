#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "poisson.h"
#include "distribution.h"

static double segment_pois_len(void *param, int nth)
{
	double lambda = *(double *)param;
	double pnum = 1.0;
	int i = 0;

	for (i = 1; i <= nth; ++i) 
		pnum *= lambda / (double)i;

	return pnum / exp(lambda);
}


struct dist *create_pois(double lambda)
{
	struct dist *pois = malloc(sizeof(struct dist));
	double *args = malloc(sizeof(double));
	*args = lambda;

	pois->param = args;
	pois->dist_type = "poisson";
	
	pois->segment_len = segment_pois_len;

	return pois;
}
