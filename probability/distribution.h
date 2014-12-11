#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#define setArgs(dist_type, param) \
	set ## dist_type ## Args(dist_type, param)

struct seginfo {
	double m;
	int nth;
};

struct dist {
	char *dist_type;

	void *param;

	struct seginfo seginfo;

	void (*add_segment)(double *distri_value, 
			    void *param, struct seginfo *seginfo);
};

void gener_distri(int *distri, int N, struct dist *dist);

void free_dist(struct dist *dist);

#endif

