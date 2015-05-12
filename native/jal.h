#ifndef JAL_H
#define JAL_H

#include "jtype.h"
#include "PC.h"
#include "regfile.h"

class jal: public jtype{
public:
    jal(int, data_mem*, PC*);
    virtual void execute();
    virtual void access();
};

#endif