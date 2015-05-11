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
	instr_mem()
	{
		for(int i=0; i<200; i++)
			program[i] = "";
		cursor=0;
	}
	//instr_mem(int);
	string load_instr(int add) {return program[add];}
	void write_instr(string in) {program[cursor++] = in;}
};

#endif