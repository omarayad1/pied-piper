#include "bne.h"

bne::bne(int rtin, int rsin, int immin, regfile* file_pntr, PC* pc_pntr){
	name = "BNE";
	rt = rtin;
	rs = rsin;
	imm = immin;
	file = file_pntr;
	pc = pc_pntr;
	branch = pc->get();
}
void bne::decode(){
	op1 = file->load_from_reg(rs);
	op2 = file->load_from_reg(rt);
	cout << this->get_name() << " has decoded with op1: " << op1 << " and op2: " <<op2<<endl;
}
void bne::execute(){
	if(op1 != op2)
	{
		branch += imm;
		pc->load(branch);
		cout << this->get_name() << " executed and branch was taken and pc is loaded with " << branch<<endl;
	}
	else
		cout << this->get_name() << " executed and branch wasn't taken\n";
}
void bne::access(){
	cout << this->get_name() << " has no mem access!\n";
}
void bne::write(){
	cout << this->get_name() << " doesn't write\n";
}