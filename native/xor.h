#ifndef XOR_H
#define XOR_H

#include "rtype.h"

class xor: public rtype
{
public:
	xor(int, int, int, regfile*);
	virtual void execute();
};

#endif