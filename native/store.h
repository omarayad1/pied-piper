#ifndef STORE_H
#define STORE_H

#include "itype.h"

class sw: public itype
{
public:
	sw(int, int, int, regfile*, data_mem*);
	virtual void decode();
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif