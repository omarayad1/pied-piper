#ifndef INSTRMEM_H
#define INSTRMEM_H

#include <string>
using namespace std;

class instr_mem
{
private:
	string program[200];	//blind assumption
	int cursor;
public:
	instr_mem();
	string load_instr(int add);
	void write_instr(string in);
};

#endif