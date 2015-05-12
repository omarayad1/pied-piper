#include "rtype.h"

rtype::rtype(){
	type = 'r';
}
int rtype::get_rs(){
	return rs;
}
int rtype::get_rt(){
	return rt;
}
int rtype::get_rd(){
	return rd;
}
void rtype::set_op1(int in){
	op1 = in;
}
void rtype::set_op2(int in){
	op2 = in;
}
int rtype::get_res(){
	return res;
}

void rtype::decode(){
	op1 = file->load_from_reg(rs);
	op2 = file->load_from_reg(rt);
	cout << this->get_name() << " has been decoded: op1: " << op1 << ", op2: " << op2 <<endl;
}

void rtype::access(){
	cout << this->get_name() << " has no mem access!\n";
}

void rtype::write(){
	file->write_to_reg(rd, res);
	cout << this->get_name() << " has written " << res << "on reg " << rd<<endl;
}