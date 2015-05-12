#include "load.h"

load::load(int rtin, int rsin, int immin, regfile* file_pntr, data_mem* dmem_pntr) {
	name = "LOAD";
	rt = rtin;
	rs = rsin;
	imm = immin;
	file = file_pntr;
	dmem = dmem_pntr;
}
void load::execute(){
	res = op1 + op2; cout << this->get_name() << " has executed with result " << res<<endl;
}
void load::access(){
	loaded = dmem->load_word(res);
	cout << this->get_name() << " has loaded " << loaded << " from the memory cell " << res<<endl;
}
void load::write(){
	file->write_to_reg(rt, loaded);
	cout << this->get_name() << " has written " << loaded << " on register " << rt<<endl;
}