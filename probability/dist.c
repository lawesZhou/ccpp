#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"
#include "binomial.h"
#include "poisson.h"
#include "print.h"

#define N 100000
#define num 1000

int main()
{
	int bino[num + 1] = {0};
	int pois[num + 1] = {0};

	double lambda = 5;
	double p = lambda / num;

	struct BinoArgs *bino_args = malloc(sizeof(struct BinoArgs));
	bino_args->n = num;
	bino_args->p = p;

	struct dist *dist_pois = create_pois(&lambda);
	gener_distri(pois, N, dist_pois);
	printArray(pois, dist_pois->seginfo.nth);
	printf("-----------------\n");

	struct dist *dist_bino = create_bino(bino_args);
	gener_distri(bino, N, dist_bino);
	printf("bino nth = %d\n",dist_bino->seginfo.nth);
	printArray(bino, dist_bino->seginfo.nth);
	gener_distri(bino, N, dist_bino);
	//gener_distri(pois, N, dist_pois);

	free(bino_args);


	return 0;
}
