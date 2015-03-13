#ifndef SATICDATA_H
#define SATICDATA_H

#include "mypainterwidget.h"

struct point {
	int x;
	double y;
};

class StaticData {
public:
	StaticData();
	virtual ~StaticData(){};
	virtual bool getnextdata(){return 1;};
	void print(MyPainterWidget *pw);
	struct point getpointValue();
protected:
	double lastprice;
	int x;
};

#endif
