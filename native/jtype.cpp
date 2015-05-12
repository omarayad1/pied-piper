#include "jtype.h"

jtype::jtype(){
	type = 'j';
}
int jtype::get_ret(){
	return ret;
}
void jtype::decode(){
	cout << "no decoding for " << this->get_name() << endl;
}
void jtype::access(){
	cout << "no memory access for " << this->get_name() << endl;
}
void jtype::write(){
	cout << "no write back for " << this->get_name() << endl;
}