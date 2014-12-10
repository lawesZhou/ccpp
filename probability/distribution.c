#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"
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

void add_segment(double **distri_value, struct dist *dist, double randnum)
{
	struct seginfo *seginfo = &dist->seginfo;
	
	while (seginfo->m < randnum) {
		*distri_value = realloc(*distri_value, 
				        (seginfo->nth + 1) * sizeof(double));
		dist->add_segment(*distri_value, dist->param, seginfo);
		printf("randnum = %lf, seginfo.m = %lf, seginfo.nth = %d\n", 
		       randnum, seginfo->m, seginfo->nth);
	}
}

void gener_distri(int *distri, int N, struct dist *dist)
{
	int i;
	double randnum;
	int val = 0;
	struct seginfo *seginfo = &dist->seginfo;

	double *distri_value = NULL;

	for (i = 0; i < N; ++i) {
		randnum = rand() / (double)RAND_MAX;

		if (randnum > seginfo->m) { 
			add_segment(&distri_value, dist, randnum);
		}
		val = binsearch(distri_value, randnum, seginfo->nth);
		printf("\nrandnum = %lf, val = %d, nth = %d, m = %lf\n", randnum,
		       val, seginfo->nth, seginfo->m);
		printArray(distri_value, seginfo->nth);

		++distri[val];
//		break;
	}

	free(distri_value);
}
