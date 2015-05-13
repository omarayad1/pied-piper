#ifndef PIPELINE_H
#define PIPELINE_H

#include "rtype.h"
#include "itype.h"
#include "jtype.h"

#include <iostream>

class pipe_line{				//this class contains the structure and behavior of the pipe line process
private:
    instruction* line[5];		//an array of 5 instrution pointers, each index in the array represents a stage in the pipeline
    PC* pc;						//contains a pointer to the PC
    bool bubble;						//a flag which is true when the pipe line needs to bubble instructions until LW completes mem access
    bool forward(int ,int& );				//forward functions contain the forwarding logic of the pipe line
    bool forward2(int&, int&, int);
    bool forward3(int ,int& );
    void flush();							//flush function flushes the instructions in the fetch and decode state when a jump or branch occurs
    int c;
public:
    pipe_line(PC*);
    void fetch(instruction*);			//fetches an instruction into the pipeline
    void decode();						//decodes the instruction
    void execute();						//executes the instruction
    void access();						//carries out data memory access
    void write();						//writes back to the register file
    bool empty();						//returns true if the pipe line is empty
    bool upline();					//this function controls the instructions movement inside the pipe line fromone stage to another every clock cycle
    void getcycle();
};

#endif