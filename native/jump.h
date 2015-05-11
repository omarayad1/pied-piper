#ifndef JUMP_H
#define JUMP_H

#include "jtype.h"

class j: public jtype{
public:
	j(int, PC*);
	virtual void execute();
};

#endif