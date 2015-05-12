#include "jal.h"

jal::jal(int jin, data_mem* dmem_pntr, PC* pc_pntr)
{
    name = "JAL";
    jadd = jin;
    dmem = dmem_pntr;
    pc = pc_pntr;
    ret = pc->get();
}

void jal::execute(){
    //concatenate ma3 old pc then
    if(!dmem->stack_is_full())
    {
        jadd = jadd << 2;
        pc->load(jadd);
        cout << this->get_name() << " has executed, loading pc with " << jadd << " and preparing old pc to be stacked\n";
    }
    else
        cout << "stack is full!" << this->get_name() << " execution has been ommtied!\n";
}
void jal::access(){
    if(!dmem->stack_is_full())
    {
        dmem->push_to_stack(ret);
        cout << this->get_name() << " has pushed " << ret << " to the stack\n";
    }
    
}