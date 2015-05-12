#include "jal.h"

jal::jal(int jin, regfile* file_pntr, PC* pc_pntr)
{
	name = "JAL";
	jadd = jin;
	file = file_pntr;
	pc = pc_pntr;
	ret = pc->get();
}
	
void jal::execute(){
	//concatenate ma3 old pc then
	pc->load(jadd);
	cout << this->get_name() << " has executed, loading pc with " << jadd << " and saving the old pc in ra\n";
}
void jal::write(){
	file->write_to_reg(15, ret);
	cout << this->get_name() << " has written " << ret << " to register ra!\n";
}