#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "poisson.h"
#include "distribution.h"

static double exp_value(int i, double lambda)
{
	double pnum = 1.0;
	int j = 0;

	for (j = 1; j <= i; ++j) 
		pnum *= lambda / (double)j;

	return pnum / exp(lambda);
}

static void add_segment_pois(double *distri_value, void *param,
		      struct seginfo *seginfo)
{
	double *lambda = (double *)param;

	int nth = seginfo->nth;

	if (nth == 0)
		distri_value[nth] = 1 / exp(*lambda);
	else
		distri_value[nth] = distri_value[nth - 1] + 
			exp_value(nth, *lambda);
}


struct dist *create_pois(double lambda)
{
	struct dist *pois = malloc(sizeof(struct dist));
	double *args = malloc(sizeof(double));
	*args = lambda;

	pois->param = args;
	pois->dist_type = "poisson";
	
	pois->add_segment = add_segment_pois;

	return pois;
}
