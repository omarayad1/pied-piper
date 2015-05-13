#include "slt.h"

slt::slt(int rdin, int rsin, int rtin, regfile* file_pntr) {
    name = "SLT";
    rd = rdin;
    rs = rsin;
    rt = rtin;
    file = file_pntr;
}

void slt::execute(){		//if op1 is less than op2 res is set to 1
    if(op1 < op2)
        res=1;
    else
        res=0;
    cout << this->get_name() << " has executed with result " << res<<endl;
    
}