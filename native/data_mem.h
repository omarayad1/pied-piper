#ifndef DATA_MEM_H
#define DATA_MEM_H

class data_mem
{
private:
	int memory[32];
public:
	data_mem();
	int load_word(int addr);
	void store_word(int addr, int val);
};

#endif