#ifndef ALU_H
#define ALU_H

class ALU
{
private:
	int op1, op2;
public:
	ALU();
	void load_operands(int&, int&);
	int execute(int);		//takes operation number
	int add();
	int sub();
	int mul();
	//.......
	//.......
};

#endif