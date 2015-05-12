#include "rtype.h"

#ifndef XOR_H
#define XOR_H


class XOR: public rtype
{
public:
	XOR(int, int, int, regfile*);
    virtual void execute();
};

#endif