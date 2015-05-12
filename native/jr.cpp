#include"jr.h"

jr::jr(int rsin, regfile* file_pntr, PC* pc_pntr)
{
	name = "JR";
	rs = rsin;
	file = file_pntr;
	pc = pc_pntr;
}
void jr::decode(){
	op1 = file->load_from_reg(rs);
	cout << this->get_name() << " decoded with jump address " << op1 << " loaded from reg " << rs<<endl;
}
void jr::execute(){
	pc->load(op1);
	cout << this->get_name() << " has excuted jumping to address " << op1 <<endl;
}
void jr::write(){
	cout << this->get_name() << " doesn't write back!\n";
}