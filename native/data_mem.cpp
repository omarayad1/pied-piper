#include "data_mem.h"

data_mem::data_mem(){
	for(int i=0; i<32; i++)
		memory[i]=0;
}
int data_mem::load_word(int addr){
	return memory[addr];
}
void data_mem::store_word(int addr, int val){
	memory[addr] = val;
}