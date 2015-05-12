#include "ble.h"

ble::ble(){
    
}

void ble::execute() {
    res = op1 + op2; cout << this->get_name() << " executed with result "<<res<<endl;
}

void ble::access(){
    cout << this->get_name() << " has no mem access!\n";
}

void ble::write(){
    file->write_to_reg(rt, res);
    cout << this->get_name() << " has written" << res << " on reg " << rt<<endl;
}