#ifndef XOR_H
#define XOR_H

#include "rtype.h"

class xor: public rtype
{
public:
	xor(int rdin, int rsin, int rtin, regfile* file_pntr) {
		name = "XOR";
		rd = rdin;
		rs = rsin;
		rt = rtin;
		file = file_pntr;
	}
	virtual void execute(){res = op1 ^ op2; cout << this->get_name() << " has executed with result " << res<<endl;}
};

#endif