#include "XOR.h"

XOR::XOR(int rdin, int rsin, int rtin, regfile* file_pntr){
	name = "XOR";
	rd = rdin;
	rs = rsin;
	rt = rtin;
	file = file_pntr;
}

void XOR::execute(){
	res = op1 ^ op2;
	cout << this->get_name() << " has executed with result " << res<<endl;
}