#include <stdio.h>

#include "gener.h"
#include "binomial.h"
#include "poisson.h"
#include "print.h"


#define N (100 * 1000)
#define num 1000

int main()
{
	int bino[num + 1] = {0};
	int pois[num + 1] = {0};

	double lambda = 5;
	double p = lambda / num;

	struct BinoArgs bino_args;
	bino_args.n = num;
	bino_args.p = p;

	gener_distri(bino, N, bino_value, &bino_args);
	printArray(bino, num);

	gener_distri(pois, N, pois_value, &lambda);
	printArray(pois, num);

	return 0;
}
