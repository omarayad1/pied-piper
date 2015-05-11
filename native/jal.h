#ifndef JAL_H
#define JAL_H

#include "jtype.h"

class jal: public jtype{
public:
	jal(int, regfile*, PC*);
	virtual void execute();
	virtual void write();
};

#endif