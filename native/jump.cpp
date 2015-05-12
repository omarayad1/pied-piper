#include "jump.h"

j::j(int jin, PC* pc_pntr)
{
	name = "J";
	jadd = jin;
	pc = pc_pntr;
}
	
void j::execute(){
	//concatenate ma3 old pc then
    jadd = jadd << 2;
    pc->load(jadd);
	cout << this->get_name() << " has executed, loading pc with " << jadd << endl;
}