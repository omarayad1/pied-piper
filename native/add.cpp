#include "add.h"

add::add(int rdin, int rsin, int rtin, regfile* file_pntr) {
	name = "ADD";
	rd = rdin;
	rs = rsin;
	rt = rtin;
	file = file_pntr;
}

void add::execute(){
	res = op1 + op2;
	cout << this->get_name() << " has executed with result " << res<<endl;
}