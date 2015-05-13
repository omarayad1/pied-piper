#include "load.h"

lw::lw(int rtin, int rsin, int immin, regfile* file_pntr, data_mem* dmem_pntr) {
	name = "LW";
	rt = rtin;
	rs = rsin;
	imm = immin;
	file = file_pntr;
	dmem = dmem_pntr;
}
void lw::execute(){
	res = op1 + op2; cout << this->get_name() << " has executed with result " << res<<endl;
}
void lw::access(){              //load the desired value from the data memory
	loaded = dmem->load_word(res);
	cout << this->get_name() << " has loaded " << loaded << " from the memory cell " << res<<endl;
}
void lw::write(){               //write loaded value ack into register file
	file->write_to_reg(rt, loaded);
	cout << this->get_name() << " has written " << loaded << " on register " << rt<<endl;
}