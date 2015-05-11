#ifndef SLT_H
#define SLT_H

#include "rtype.h"

class slt: public rtype
{
public:
	slt(int, int, int, regfile*);
	virtual void execute();
};

#endif