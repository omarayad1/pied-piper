#ifndef ADDI_H
#define ADDI_H

#include "itype.h"

class addi: public itype
{
public:
	addi(int rtin, int rsin, int immin, regfile* file_pntr) {
		name = "ADDI";
		rt = rtin;
		rs = rsin;
		imm = immin;
		file = file_pntr;
	}
	virtual void execute() {res = op1 + op2; cout << this->get_name() << " executed with result "<<res<<endl;}
	virtual void access(){
		cout << this->get_name() << " has no mem access!\n";
	}
	virtual void write(){
		file->write_to_reg(rt, res);
		cout << this->get_name() << " has written" << res << " on reg " << rt<<endl;
	}
};

#endif