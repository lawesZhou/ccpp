#ifndef TEXTDATA_H
#define TEXTDATA_H

#include <string>
#include <iostream>

#include "static_data.h"

class TextData : public StaticData {
public:
	TextData();
	TextData(std::string filename);
	virtual ~TextData();

	virtual bool getnextdata();
private:
	std::string src_dir;
	std::string filename;
	FILE *fp;
};

#endif
