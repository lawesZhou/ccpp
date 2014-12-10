#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"
#include "binomial.h"
//#include "poisson.h"
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

	char *dist_type = "bino";
	struct dist *dist_bino = create_bino(dist_type, bino_args);
	gener_distri(bino, N, dist_bino);
//	printArray(bino, num);

//	gener_distri(pois, N, dist_pois);
//	printArray(pois, num);

	return 0;
}
