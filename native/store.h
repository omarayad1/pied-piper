#ifndef STORE_H
#define STORE_H

#include "itype.h"

class store: public itype
{
public:
	store(int rtin, int rsin, int immin, regfile* file_pntr, data_mem* dmem_pntr) {
		name = "STO";
		rt = rtin;
		rs = rsin;
		imm = immin;
		file = file_pntr;
		dmem = dmem_pntr;
	}
	virtual void decode(){
		op1 = file->load_from_reg(rs);
		op2 = imm;
		loaded = file->load_from_reg(rt);
		cout << this->get_name() << " has decoded, op1: "<< op1 << " and op2: " << op2 << " with store data: "<< loaded<<endl;
	}
	virtual void execute() {res = op1 + op2; cout << this->get_name() << " has executed with result " << res<<endl;}
	virtual void access(){
		dmem->store_word(res, loaded);
		cout << this->get_name() << " has stored " << loaded << " in the memory cell " << res<<endl;
	}
	virtual void write() {cout << this->get_name() << " doesn't write back!\n";}
};

#endif