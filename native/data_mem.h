#ifndef DATA_MEM_H
#define DATA_MEM_H

class data_mem
{
private:
	int memory[32];
public:
	data_mem(){
		for(int i=0; i<32; i++)
			memory[i]=0;
	}
	int load_word(int addr) {return memory[addr];}
	void store_word(int addr, int val) {memory[addr] = val;}
};

#endif