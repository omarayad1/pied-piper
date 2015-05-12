#include "intsr_mem.h"

instr_mem::instr_mem()
{
	for(int i=0; i<200; i++)
		program[i] = "";
	cursor=0;
}
string instr_mem::load_instr(int add){
	return program[add];
}
void instr_mem::write_instr(string in){
	program[cursor++] = in;
}