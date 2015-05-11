#include "PC.h"
#include "intsr_mem.h"
#include "regfile.h"
#include "data_mem.h"
#include "pipe_line.h"
#include "add.h"
#include "load.h"
#include "xor.h"
#include "slt.h"
#include "store.h"
#include "addi.h"
#include "jump.h"
#include "jr.h"
#include "jal.h"
#include <iostream>

static PC SIM_pc;
static instr_mem SIM_imem;
static regfile SIM_file;
static data_mem SIM_dmem;
static pipe_line pipe;

void Load();

int main()
{
	SIM_imem.write_instr("ADDI");
	SIM_imem.write_instr("JAL");
	SIM_imem.write_instr("ADD");
	SIM_imem.write_instr("JR");
	//SIM_imem.write_instr("STO");
	
	bool stall=false;;
	int cycle=1;

	do{
		cout << "cycle " << cycle <<endl;
		if(!stall)
			Load();
		pipe.write();
		pipe.decode();
		pipe.execute();
		pipe.access();
		stall = pipe.upline();
		cycle++;
		system("pause");
	}
	while(!pipe.empty());
	cout << SIM_file.load_from_reg(15) << "  " << SIM_dmem.load_word(0)<<endl;
	return 0;
}

void Load()
{
	static int c=0;
	string inst;
	inst = SIM_imem.load_instr(SIM_pc.get());
	if(inst != "")
	{
		SIM_pc.increment();
		if(inst == "ADD")
			if(c<2)
				pipe.fetch(new add(2, 1, 0, &SIM_file));
			else
				pipe.fetch(new add(4, 2, 3, &SIM_file));

		else if(inst == "XOR")
			pipe.fetch(new xor(2, 1, 0, &SIM_file));
		else if(inst == "SLT")
			pipe.fetch(new slt(2, 1, 0, &SIM_file));
		else if (inst == "LOAD")
			pipe.fetch(new load(4, 0, 0, &SIM_file, &SIM_dmem));
		else if(inst == "STO")
			pipe.fetch(new store(4, 0, 0, &SIM_file, &SIM_dmem));
		else if(inst == "ADDI")
			if(c<1)
				pipe.fetch(new addi(1, 0, 5, &SIM_file));
			else
				pipe.fetch(new addi(1, 0, 1, &SIM_file));
		else if(inst == "J")
			pipe.fetch(new j(0, &SIM_pc));
		else if(inst == "JAL")
			pipe.fetch(new jal(0, &SIM_file, &SIM_pc));
		else if(inst == "JR")
			pipe.fetch(new jr(1, &SIM_file, &SIM_pc));
		c++;
	}
}