#ifndef JTYPE_H
#define JTYPE_H

#include "instruction.h"
#include "PC.h"

class jtype: public instruction
{
protected:
	int jadd, ret;
	PC* pc;
public:
	jtype() {type = 'j';}
	int get_ret() {return ret;}
	virtual void decode(){cout << "no decoding for " << this->get_name() << endl;}
	virtual void access(){cout << "no memory access for " << this->get_name() << endl;}
	virtual void write(){cout << "no write back for " << this->get_name() << endl;}
};

#endif