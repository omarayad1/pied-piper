#ifndef REGFILE_H
#define REGFILE_H

#include "reg.h"

class regfile
{
private:
	int file[32];
public:
	regfile() {
		for(int i=0; i<16; i++)
			file[i]=0;
	}
	void write_to_reg(int radd, int val) {file[radd] = val;}
	int load_from_reg(int radd) {return file[radd];}
};

#endif