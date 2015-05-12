#include "xor.h"

xor::xor(int rdin, int rsin, int rtin, regfile* file_pntr){
	name = "XOR";
	rd = rdin;
	rs = rsin;
	rt = rtin;
	file = file_pntr;
}

void xor::execute(){
	res = op1 ^ op2;
	cout << this->get_name() << " has executed with result " << res<<endl;
}