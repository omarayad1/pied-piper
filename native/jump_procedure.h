#ifndef JMPRO_H
#define JMPRO_H

#include "jtype.h"
#include "PC.h"
#include "regfile.h"

class jmpro: public jtype{
public:
    jmpro(int, data_mem*, PC*);
    virtual void execute();
    virtual void access();
};

#endif