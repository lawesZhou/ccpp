#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"
#include "binomial.h"
#include "poisson.h"
#include "print.h"

#define N 10000000
#define n 1000

int main()
{
	int bino[n + 1] = {0};
	int pois[n + 1] = {0};

	double lambda = 5;
	double p = lambda / n;

	struct dist *dist_bino = create_bino(n, p);
	gener_distri(bino, N, dist_bino);
	printf("bino nth = %d\n",dist_bino->seginfo.nth);
	printArray(bino, dist_bino->seginfo.nth);

	printf("-----------------\n");
	struct dist *dist_pois = create_pois(lambda);
	gener_distri(pois, N, dist_pois);
	printArray(pois, dist_pois->seginfo.nth);

	free_dist(dist_bino);
	free_dist(dist_pois);

	return 0;
}
