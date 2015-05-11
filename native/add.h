#ifndef ADD_H
#define ADD_H

#include "rtype.h"
#include <iostream>

class add: public rtype
{
public:
	add(int rdin, int rsin, int rtin, regfile* file_pntr) {
		name = "ADD";
		rd = rdin;
		rs = rsin;
		rt = rtin;
		file = file_pntr;
	}
	virtual void execute();
};

#endif