#ifndef ITYPE_H
#define ITYPE_H

#include "instruction.h"

using namespace std;
class itype: public instruction
{
protected:
    int rs, imm, rt, branch;
    int op1, op2, res, loaded;
public:
    itype();
    int get_rs();
    int get_rt();
    void set_op1(int);
    void set_op2(int);
    int get_res();
    void set_load(int);
    int get_loaded();
    
    virtual void decode();
};

#endif