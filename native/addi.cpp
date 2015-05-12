#include "addi.h"

addi::addi(int rtin, int rsin, int immin, regfile* file_pntr) {
	name = "ADDI";
	rt = rtin;
	rs = rsin;
	imm = immin;
	file = file_pntr;
}
void addi::execute(){
	res = op1 + op2;
	cout << this->get_name() << " executed with result "<<res<<endl;
}
void addi::access(){
	cout << this->get_name() << " has no mem access!\n";
}
void addi::write(){
	file->write_to_reg(rt, res);
	cout << this->get_name() << " has written " << res << " on reg " << rt<<endl;
}