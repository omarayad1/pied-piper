#ifndef STORE_H
#define STORE_H

#include "itype.h"

class store: public itype
{
public:
	store(int, int, int, regfile*, data_mem*);
	virtual void decode();
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif