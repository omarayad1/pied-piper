#ifndef ITYPE_H
#define ITYPE_H

#include "instruction.h"
#include "data_mem.h"
#include <iostream>

using namespace std;
class itype: public instruction
{
protected:
	int rs, imm, rt;
	int op1, op2, res, loaded;
	data_mem* dmem;
public:
	itype();
	int get_rs();
	int get_rt();
	void set_op1(int in);
	int get_res();
	void set_load(int in);
	int get_loaded();

	virtual void decode();
};

#endif