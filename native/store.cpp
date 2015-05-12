#include "store.h"

store::store(int rtin, int rsin, int immin, regfile* file_pntr, data_mem* dmem_pntr) {
	name = "STO";
	rt = rtin;
	rs = rsin;
	imm = immin;
	file = file_pntr;
	dmem = dmem_pntr;
}
void store::decode(){
	op1 = file->load_from_reg(rs);
	op2 = imm;
	loaded = file->load_from_reg(rt);
	cout << this->get_name() << " has decoded, op1: "<< op1 << " and op2: " << op2 << " with store data: "<< loaded<<endl;
}
void store::execute(){
	res = op1 + op2; cout << this->get_name() << " has executed with result " << res<<endl;}

void store::access(){
	dmem->store_word(res, loaded);
	cout << this->get_name() << " has stored " << loaded << " in the memory cell " << res<<endl;
}
void store::write(){
	cout << this->get_name() << " doesn't write back!\n";
}