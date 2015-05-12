#ifndef BNE_H
#define BNE_H

#include "itype.h"

class bne: public itype{
public:
	bne(int, int, int, regfile*, PC*);
	virtual void decode();
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif