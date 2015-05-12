#include "PC.h"
#include "intsr_mem.h"
#include "regfile.h"
#include "data_mem.h"
#include "pipe_line.h"
#include "add.h"
#include "xor.h"
#include "slt.h"
#include "jr.h"
#include "addi.h"
#include "load.h"
#include "store.h"
#include "bne.h"
#include "jump.h"
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
	SIM_imem.write_instr("BNE");
	SIM_imem.write_instr("LOAD");
	SIM_imem.write_instr("ADD");
	SIM_imem.write_instr("XOR");
	SIM_imem.write_instr("SLT");
	
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
			pipe.fetch(new add(5, 6, 1, &SIM_file));
		else if(inst == "XOR")
			pipe.fetch(new xor(3, 4, 0, &SIM_file));
		else if(inst == "SLT")
			pipe.fetch(new slt(2, 1, 0, &SIM_file));
		else if(inst == "JR")
			pipe.fetch(new jr(1, &SIM_file, &SIM_pc));
		else if(inst == "ADDI")
			pipe.fetch(new addi(1, 0, 10, &SIM_file));
		else if (inst == "LOAD")
			pipe.fetch(new load(2, 6, 0, &SIM_file, &SIM_dmem));
		else if(inst == "STO")
			pipe.fetch(new store(1, 2, 0, &SIM_file, &SIM_dmem));
		else if(inst == "BNE")
			pipe.fetch(new bne(1, 2, 3, &SIM_file, &SIM_pc));
		else if(inst == "J")
			pipe.fetch(new j(0, &SIM_pc));
		else if(inst == "JAL")
			pipe.fetch(new jal(0, &SIM_file, &SIM_pc));
		
		c++;
	}
}