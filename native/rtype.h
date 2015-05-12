#ifndef RTYPE_H
#define RTYPE_H

#include "instruction.h"
#include "PC.h"
#include <iostream>

class rtype: public instruction
{
protected:
	int rs, rt, rd;
	int op1, op2, res;
public:
	rtype();
	int get_rs();
	int get_rt();
	int get_rd();
	void set_op1(int);
	void set_op2(int);
	int get_res();
	
	virtual void decode();
	virtual void access();
	virtual void write();
};

#endif