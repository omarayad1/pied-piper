#ifndef RTYPE_H
#define RTYPE_H

#include "instruction.h"
#include "PC.h"
#include <iostream>

class rtype: public instruction				//rtype instruction inherits from instruction class
{
protected:
    int rs, rt, rd;				//rs, rt and rd register
    int op1, op2, res;			//values extracted from the registers
public:
    rtype();
    int get_rs();			//returns rs register
    int get_rt();			//returns rt register
    int get_rd();			//returns rd register
    void set_op1(int);		//set operand 1 value
    void set_op2(int);		//set operand 2 value
    int get_res();			//return the result calculated
    
    virtual void decode();			//implementing, access and write
    virtual void access();
    virtual void write();
};

#endif