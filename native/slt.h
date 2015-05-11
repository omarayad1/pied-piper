#ifndef SLT_H
#define SLT_H

#include "rtype.h"

class slt: public rtype
{
public:
	slt(int rdin, int rsin, int rtin, regfile* file_pntr) {
		name = "SLT";
		rd = rdin;
		rs = rsin;
		rt = rtin;
		file = file_pntr;
	}
	virtual void execute(){
		if(op1 < op2)
			res=1;
		else
			res=1;
		cout << this->get_name() << " has executed with result " << res<<endl;
	}
};

#endif