#ifndef BINOMIAL_H
#define BINOMIAL_H

struct BinoArgs{
	int n;
	double p;
};

double *bino_value(int *n, void *param);

#endif
