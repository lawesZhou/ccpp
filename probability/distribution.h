#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

struct seginfo {
	double m;
	int nth;
};

struct dist {
	char *dist_type;

	void *param;

	struct seginfo seginfo;

	double (*segment_len)(void *param, int nth);
};

void gener_distri(int *distri, int N, struct dist *dist);

void free_dist(struct dist *dist);

#endif

