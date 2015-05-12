#ifndef JTYPE_H
#define JTYPE_H

#include "instruction.h"
#include "PC.h"
#include <iostream>

class jtype: public instruction
{
protected:
	int jadd, ret;
public:
	jtype();
	int get_ret();
	virtual void decode();
	virtual void access();
	virtual void write();
};

#endif