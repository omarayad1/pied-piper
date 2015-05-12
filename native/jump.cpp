#include "jump.h"

j::j(int jin, PC* pc_pntr)
{
	name = "J";
	jadd = jin;
	pc = pc_pntr;
}
	
void j::execute(){
	//concatenate ma3 old pc then
    int temp1;
    temp1 = pc->get();
    //temp1 = ((temp1/268435456)*268435456) + (jadd*4);
    temp1 = ((temp1>>28)<<28) + (jadd*4);
    
    pc->load(temp1);
	cout << this->get_name() << " has executed, loading pc with " << jadd << endl;
}