#ifndef LOAD_H
#define LOAD_H

#include "itype.h"
#include "regfile.h"
#include "data_mem.h"

class lw: public itype
{
public:
	lw(int, int, int, regfile*, data_mem*);
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif