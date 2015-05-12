#include "regfile.h"

regfile::regfile() {
	for(int i=0; i<16; i++)
		file[i]=0;
}
void regfile::write_to_reg(int radd, int val){
	file[radd] = val;
}
int regfile::load_from_reg(int radd){
	return file[radd];
}