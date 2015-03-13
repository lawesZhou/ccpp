#ifndef SATICDATA_H
#define SATICDATA_H

#include "mypainterwidget.h"

struct point {
	int x;
	double y;
};

class StaticData {
public:
	MyPainterWidget *pw;

	StaticData(){};
	virtual ~StaticData(){};
	virtual bool getnextdata(){return 1;};
	void print();
	struct point getpointValue();
protected:
	double lastprice;
	int x;
};

#endif
