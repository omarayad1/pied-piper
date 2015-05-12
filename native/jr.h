#ifndef JR_H
#define JR_H

#include "rtype.h"

class jr: public rtype{
public:
	jr(int, regfile*, PC*);
	virtual void decode();
	virtual void execute();
	virtual void write();
};

#endif