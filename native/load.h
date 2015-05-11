#ifndef LOAD_H
#define LOAD_H

#include "itype.h"

class load: public itype
{
public:
	load(int rtin, int rsin, int immin, regfile* file_pntr, data_mem* dmem_pntr) {
		name = "LOAD";
		rt = rtin;
		rs = rsin;
		imm = immin;
		file = file_pntr;
		dmem = dmem_pntr;
	}
	virtual void execute() {res = op1 + op2; cout << this->get_name() << " has executed with result " << res<<endl;}
	virtual void access(){
		loaded = dmem->load_word(res);
		cout << this->get_name() << " has loaded " << loaded << " from the memory cell " << res<<endl;
	}
	virtual void write(){
		file->write_to_reg(rt, loaded);
		cout << this->get_name() << " has written " << loaded << " on register " << rt<<endl;
	}
};

#endif