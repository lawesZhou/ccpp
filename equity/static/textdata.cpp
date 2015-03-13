#include <cstdio>
#include <cstdlib>

#include "textdata.h"

using namespace std;

TextData::TextData()
{
	filename = "000001.lastprice";
	fp = fopen(filename.c_str(), "r");

	if (fp == NULL) {
		perror("failed to open this file");
		exit(-1);
	}
	cout << "open file success" << endl;
} 

TextData::TextData(string filename): filename(filename)
{
	fp = fopen(filename.c_str(), "r");

	if (fp == NULL) {
		perror("failed to open this file");
		exit(-1);
	}
}

TextData::~TextData()
{
	if (fp)	
		fclose(fp);
}

bool TextData::getnextdata()
{
	if (fscanf(fp, "%lf", &lastprice) != 1) {
		return false;
	}

	++x;
	return true;
}
