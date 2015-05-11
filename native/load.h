#ifndef LOAD_H
#define LOAD_H

#include "itype.h"

class load: public itype
{
public:
	load(int, int, int, regfile*, data_mem*);
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif