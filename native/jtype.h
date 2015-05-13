#ifndef JTYPE_H
#define JTYPE_H

#include "instruction.h"
#include "PC.h"
#include <iostream>

class jtype: public instruction         //jtype instruction inherits from instruction class
{
protected:
	int jadd, ret;                      //jump address and return address
public:
	jtype();
	int get_ret();                      //returns return address
	virtual void decode();              //implement decode, access and write
	virtual void access();
	virtual void write();
};

#endif