#ifndef ITYPE_H
#define ITYPE_H

#include "instruction.h"

using namespace std;
class itype: public instruction         //rtype instruction inherits from instruction class
{
protected:
    int rs, imm, rt, branch;            //rs and rt register, immediate and branch value
    int op1, op2, res, loaded;          //operands, result and loaded values
public:
    itype();
    int get_rs();                       //returns rs register
    int get_rt();                       //returns rd register
    void set_op1(int);                  //set operand 1 value
    void set_op2(int);                  //set operand 2 value
    int get_res();                      //return the result calculated
    void set_load(int);                 //set load value
    int get_loaded();                   //get load value
    
    virtual void decode();              //implement decode
};

#endif