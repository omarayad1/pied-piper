#ifndef JUMP_H
#define JUMP_H

#include "jtype.h"

class j: public jtype{
public:
	j(int jin, PC* pc_pntr)
	{
		name = "J";
		jadd = jin;
		pc = pc_pntr;
	}
	
	virtual void execute(){
		//concatenate ma3 old pc then
		pc->load(jadd);
		cout << this->get_name() << " has executed, loading pc with " << jadd << endl;
	}
};

#endif