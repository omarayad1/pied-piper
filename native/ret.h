#ifndef RET_H
#define RET_H

#include "instruction.h"

class ret: public instruction{
public:
    ret(data_mem*, PC*);
    virtual void decode();
    virtual void execute();
    virtual void access();
    virtual void write();
};

#endif