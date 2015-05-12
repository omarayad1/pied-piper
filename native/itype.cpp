#include "itype.h"

itype::itype(){
	type = 'i';
}
int itype::get_rs(){
	return rs;
}
int itype::get_rt(){
	return rt;
}
void itype::set_op1(int in){
	op1 = in;
}
void itype::set_op2(int in){
	op2 = in;
}
int itype::get_res(){
	return res;
}
void itype::set_load(int in){
	loaded = in;
}
int itype::get_loaded(){
	return loaded;
}
void itype::decode(){
	op1 = file->load_from_reg(rs);
	op2 = imm;
	cout << this->get_name() << " has decoded, op1: "<< op1 << " and op2: " << op2<<endl;
}