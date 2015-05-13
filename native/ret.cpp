#include "ret.h"

ret::ret(data_mem* dmem_pntr, PC* pc_pntr){
    name = "RET";
    type = 'n';
    dmem = dmem_pntr;
    pc = pc_pntr;
}

void ret::decode(){
    cout << this->get_name() << " has no decode!\n";
}

void ret::execute(){				//if stack is not empty return pops the last address in the stack and loads it into the pc
    if(dmem->stack_is_empty())
    {
        cout << "stack is empty!" << this->get_name() << " execution has been ommited\n";
    }
    else
    {
        int ret = dmem->pop_from_stack();
        pc->load(ret);
        cout << this->get_name() << " has executed loading the pc with " <<ret<<endl;
    }
}

void ret::access(){
    cout << this->get_name() << " has no memory access!\n";
}

void ret::write(){
    cout << this->get_name() << " has no write back!\n";
}