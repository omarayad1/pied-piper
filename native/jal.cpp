#include "jal.h"

jal::jal(int jin, regfile* file_pntr, PC* pc_pntr)
{
    name = "JAL";
    jadd = jin;
    file = file_pntr;
    pc = pc_pntr;
    ret = pc->get();			//loads return value with current pc
}

void jal::execute(){
    int temp1;
    temp1 = pc->get();
    //temp1 = ((temp1/268435456)*268435456) + (jadd*4);
    temp1 = ((temp1>>28)<<28) + (jadd*4);
    pc->load(temp1);
    cout << this->get_name() << " has executed, loading pc with " << jadd << " and preparing old pc to be stored in ra\n";
}
void jal::write(){
    file->write_to_reg(15, ret);		//return address is written on reg 15 (ra)
    cout << this->get_name() << " has written " << ret << " on ra\n";
    
}