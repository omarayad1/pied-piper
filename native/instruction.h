#ifndef INSTR_H
#define INSTR_H

#include <string>
#include "regfile.h"

using namespace std;

class instruction
{
protected:
	string name;
	char type;
	regfile* file;
public:
	instruction(){}
	string get_name();
	char get_type();

	virtual void decode()=0;
	virtual void execute()=0;
	virtual void access()=0;
	virtual void write()=0;
};

#endif