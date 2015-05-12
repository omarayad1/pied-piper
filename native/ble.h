#ifndef BLE_H
#define BLE_H

#include "itype.h"

class ble: public itype{
public:
    ble();
    virtual void execute();
    virtual void access();
    virtual void write();
};

#endif