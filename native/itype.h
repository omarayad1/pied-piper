#ifndef ITYPE_H
#define ITYPE_H

#include "instruction.h"

#include <iostream>
using namespace std;
class itype: public instruction
{
protected:
	int rs, imm, rt;
	int op1, op2, res, loaded;
	data_mem* dmem;
public:
	itype() {type = 'i';}
	int get_rs() {return rs;}
	int get_rt() {return rt;}
	void set_op1(int in) {op1 = in;}
	int get_res() {return res;}
	void set_load(int in) {loaded = in;}
	int get_loaded() {return loaded;}

	virtual void decode(){
		op1 = file->load_from_reg(rs);
		op2 = imm;
		cout << this->get_name() << " has decoded, op1: "<< op1 << " and op2: " << op2<<endl;
	}
};

#endif