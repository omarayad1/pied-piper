#ifndef PC_H
#define PC_H

class PC
{
private:
	int counter;
public:
	PC();
	int get();
	void increment();
	void load(int add);
};

#endif