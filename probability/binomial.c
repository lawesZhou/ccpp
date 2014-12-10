#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <string.h>

#include "distribution.h"
#include "binomial.h"

static double combin_num(int n, int i);

struct dist *create_bino(struct BinoArgs *param)
{
	struct dist *args = (struct dist *)malloc(sizeof(struct dist));
	args->dist_type = "binomial";
	args->param = param;

	args->seginfo.m = 0;//if need to initiate
	args->seginfo.nth = 0;

	args->add_segment = add_segment_bino;

	return args;
}

void add_segment_bino(double *distri_value, 
		      void *param, struct seginfo *seginfo)
{
	struct BinoArgs *args = (struct BinoArgs *)param;
	int n = args->n;
	double p = args->p;
	int nth = seginfo->nth;
	
	if (nth == 0)
		distri_value[nth] = pow((1 - p), n);
	else
		distri_value[nth] = distri_value[nth - 1] + combin_num(n, nth)  
			            * pow(p, nth) * pow((1 - p), n - nth);
//	printf("%lf\n", combin_num(n, nth)  
//		* pow(p, nth) * pow((1 - p), n - nth));
	seginfo->m = distri_value[nth];
	++seginfo->nth;
}

static double combin_num(int n, int i)
{
	double cn = 1.0;

	if (i == 0 || n == i)
		return 1;

	if (i > n / 2)
		i = n - i;

//	printf("c(%d, %d) = ", n, i);
	for (; i > 0; --i, --n) 
		cn *= (double)n / i;

//	printf("%lf\n", cn);
	return cn;
}

double *bino_value(int *n, void *param)
{
	struct BinoArgs * bino_param = (struct BinoArgs *)param;
	*n = bino_param->n;

	double p = bino_param->p;

	int i = 0;

	printf("args of bino_value:n = %d, lambda = %lf\n", *n, p);

	/* B() = (n,p)*p^i*(1-p)(n-i)*/
	double *pbino = malloc((*n + 1) * sizeof(double));
	memset(pbino, 0, (*n + 1) * sizeof(double));

	for (i = 0; i < *n + 1; ++i) {
		if (i == 0)
			pbino[i] = pow((1 - p), *n - i);
		else
			pbino[i] = pbino[i - 1] + combin_num(*n, i)   
				   * pow(p, i) * pow((1 - p), *n - i);

		printf("pbino[%d] = %lf\n", i, pbino[i]);
	}	

	return pbino;
}

