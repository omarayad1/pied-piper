#ifndef INSTR_H
#define INSTR_H

#include <string>
#include "regfile.h"
#include "PC.h"
#include "data_mem.h"
#include <iostream>

using namespace std;

class instruction           //base class for all instruction classes
{
protected:
    string name;            // instruction name
    char type;              // instruction type
    regfile* file;          // pointer to the register file
    PC* pc;                 // pointer to the PC
    data_mem* dmem;         // pointer to the data memory
public:
    instruction(){}
    string get_name();      // returns instruction name
    char get_type();        // returns instruction type
    
    virtual void decode()=0;        //virtual decode function that is overrided in sub clases
    virtual void execute()=0;       //virtual execute function that is overrided in sub classes
    virtual void access()=0;        //virtual access function that is overried in sub classes
    virtual void write()=0;         //virtual write back function that is overried in sub classes
};

#endif