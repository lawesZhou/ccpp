#include <stdio.h>
#include <unistd.h>

#include "static_data.h"

std::vector<struct point> pointSet;

void
StaticData::print()
{
	while (getnextdata()) {
		struct point p = getpointValue();
//		printf("%d %lf\n", p.x, p.y);

		pointSet.push_back(p);
	}
	printf("point size = %lu\n", pointSet.size());
	pw->repaint();
}

struct point 
StaticData::getpointValue()
{
	struct point p;
	p.x = x;
	p.y = lastprice;
	return p;
}
