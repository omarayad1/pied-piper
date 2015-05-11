#ifndef PIPELINE_H
#define PIPELINE_H

#include "rtype.h"
#include "itype.h"
#include "jtype.h"

#include <iostream>

class pipe_line{
private:
	instruction* line[5];
	bool bubble;
	bool forward(int ,int& );
	bool forward2(int&, int&, int);
public:
	pipe_line();
	void fetch(instruction*);
	void decode();
	void execute();
	void access();
	void write();
	bool empty();
	bool upline();
};

#endif