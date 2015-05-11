#ifndef PC_H
#define PC_H

class PC
{
private:
	int counter;
public:
	PC() {counter = 0;}
	int get() {return counter;}
	void increment() {counter++;}
	void load(int add){counter = add;}
};

#endif