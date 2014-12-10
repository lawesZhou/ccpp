#ifndef BINOMIAL_H
#define BINOMIAL_H

#include "distribution.h"

struct BinoArgs {
	int n;
	double p;
};

struct dist *create_bino(struct BinoArgs *param);

void add_segment_bino(double *distri_value, 
		      void *param, struct seginfo *seginfo);
#endif
