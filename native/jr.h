#ifndef JR_H
#define JR_H

#include "rtype.h"
#include "PC.h"
#include "regfile.h"

class jr: public rtype{
public:
	jr(int, regfile*, PC*);
	virtual void decode();
	virtual void execute();
	virtual void write();
};

#endif