#ifndef ADD_H
#define ADD_H

#include "rtype.h"
#include <iostream>

class add: public rtype
{
public:
	add(int, int, int, regfile*);
	virtual void execute();
};

#endif