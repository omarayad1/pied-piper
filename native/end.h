#ifndef END_H
#define END_H

#include "instruction.h"

class endp: public instruction{
public:
    endp(PC*);
    virtual void decode();
    virtual void execute();
    virtual void access();
    virtual void write();
};

#endif