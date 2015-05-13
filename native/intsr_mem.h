#ifndef INSTRMEM_H
#define INSTRMEM_H

#include <map>
#include <string>
using namespace std;

class instr_mem
{
private:
	string program[200];	//an array that holds all instructions
	int cursor;             //a cursor that points to the last instruction written to the memory
public:
	instr_mem();
	string load_instr(int add);             // loads an instruction from the memory
	void write_instr(string in);            // writes a new instruction to the memory
};

#endif