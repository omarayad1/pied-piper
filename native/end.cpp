#include "end.h"

endp::endp(PC* pc_pntr){
    name = "END";
    type = 'n';
    pc = pc_pntr;
}

void endp::decode(){
    cout << this->get_name() << " has no decode!\n";
}

void endp::execute(){
    //load instruction mem with last address
    pc->load(199);
    cout << this->get_name() << " has executed endingt the program!\n";
}

void endp::access(){
    cout << this->get_name() << " has no memory access!\n";
}

void endp::write(){
    cout << this->get_name() << " has no write back!\n";
}