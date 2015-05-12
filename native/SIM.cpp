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
#include "ret.h"
#include "end.h"
#include <iostream>

static PC SIM_pc;
static instr_mem SIM_imem;
static regfile SIM_file;
static data_mem SIM_dmem;
static pipe_line pipe(&SIM_pc);

void Load();

int main()
{
    SIM_imem.write_instr("ADDI");
    SIM_imem.write_instr("J");
    SIM_imem.write_instr("SLT");
    SIM_imem.write_instr("XOR");
    SIM_imem.write_instr("ADD");
    SIM_imem.write_instr("SLT");
    SIM_imem.write_instr("ADD");
    SIM_imem.write_instr("LOAD");
    SIM_imem.write_instr("STO");
    
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
        //system("pause");
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
            pipe.fetch(new add(4, 1, 0, &SIM_file));
        else if(inst == "XOR")
            pipe.fetch(new XOR(3, 4, 0, &SIM_file));
        else if(inst == "SLT")
            pipe.fetch(new slt(2, 1, 0, &SIM_file));
        else if(inst == "JR")
            pipe.fetch(new jr(1, &SIM_file, &SIM_pc));
        else if(inst == "ADDI")
            pipe.fetch(new addi(1, 0, 5, &SIM_file));
        else if (inst == "LW")
            pipe.fetch(new lw(3, 4, 1, &SIM_file, &SIM_dmem));
        else if(inst == "SW")
            pipe.fetch(new sw(3, 0, 0, &SIM_file, &SIM_dmem));
        else if(inst == "BNE")
            pipe.fetch(new bne(9, 2, 3, &SIM_file, &SIM_pc));
        else if(inst == "J")
            pipe.fetch(new j(7, &SIM_pc));
        else if(inst == "JAL")
            pipe.fetch(new jal(4, &SIM_dmem, &SIM_pc));
        else if(inst == "RET")
            pipe.fetch(new ret(&SIM_dmem, &SIM_pc));
        else if(inst == "END")
            pipe.fetch(new endp(&SIM_pc));
        
        c++;
    }
}