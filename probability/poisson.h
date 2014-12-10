#ifndef POISSON_H
#define POISSON_H

#include "distribution.h"

struct dist *create_pois(double *lambda);

void add_segment_pois(double *distri_value, void *param,
		      struct seginfo *seginfo);

#endif
