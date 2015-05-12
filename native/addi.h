#ifndef ADDI_H
#define ADDI_H

#include "itype.h"
#include "regfile.h"

class addi: public itype
{
public:
	addi(int, int, int, regfile*);
	virtual void execute();
	virtual void access();
	virtual void write();
};

#endif