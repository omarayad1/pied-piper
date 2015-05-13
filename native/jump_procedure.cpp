#include "jump_procedure.h"

jmpro::jmpro(int jin, data_mem* dmem_pntr, PC* pc_pntr)
{
    name = "JMPROC";
    jadd = jin;
    dmem = dmem_pntr;
    pc = pc_pntr;
    ret = pc->get();			//loads return value with current pc
}

void jmpro::execute(){
    //concatenate ma3 old pc then
    if(!dmem->stack_is_full())			//load jump address into current pc
    {
        int temp1;
        temp1 = pc->get();
        //temp1 = ((temp1/268435456)*268435456) + (jadd*4);
        temp1 = ((temp1>>28)<<28) + (jadd*4);
        pc->load(temp1);
        cout << this->get_name() << " has executed, loading pc with " << jadd << " and preparing old pc to be stacked\n";
    }
    else
        cout << "stack is full!" << this->get_name() << " execution has been ommtied!\n";
}
void jmpro::access(){
    if(!dmem->stack_is_full())			//if stak is not full
    {
        dmem->push_to_stack(ret);		//current pc is pushed into stack
        cout << this->get_name() << " has pushed " << ret << " to the stack\n";
    }
    
}