#ifndef BLE_H
#define BLE_H

#include "itype.h"

class ble: public itype{
public:
	ble(){

	}
	virtual void execute() {res = op1 + op2; cout << this->get_name() << " executed with result "<<res<<endl;}
	virtual void access(){
		cout << this->get_name() << " has no mem access!\n";
	}
	virtual void write(){
		file->write_to_reg(rt, res);
		cout << this->get_name() << " has written" << res << " on reg " << rt<<endl;
	}
};

#endif