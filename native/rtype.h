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
	PC* pc;
public:
	rtype() {type = 'r';}
	int get_rs() {return rs;}
	int get_rt() {return rt;}
	int get_rd() {return rd;}
	void set_op1(int in) {op1 = in;}
	void set_op2(int in) {op2 = in;}
	int get_res() {return res;}
	
	virtual void decode(){
		op1 = file->load_from_reg(rs);
		op2 = file->load_from_reg(rt);
		cout << this->get_name() << " has been decoded: op1: " << op1 << ", op2: " << op2 <<endl;
	}
	virtual void access(){cout << this->get_name() << " has no mem access!\n";}
	virtual void write(){
		file->write_to_reg(rd, res);
		cout << this->get_name() << " has written " << res << "on reg " << rd<<endl;
	}
};

#endif