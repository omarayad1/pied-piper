#ifndef ADDI_H
#define ADDI_H

#include "itype.h"

class addi: public itype
{
public:
	addi(int, int, int, regfile*);
	virtual void execute();             // implement execute, access, write functions
	virtual void access();
	virtual void write();
};

#endif