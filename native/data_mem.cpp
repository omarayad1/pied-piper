#include "data_mem.h"

data_mem::data_mem(){
    //memory = new int(mem_size+1);
    for(int i=0; i<32; i++)
        memory[i]=0;
    
    for(int i=0; i<4; i++)
        stack[i]=0;
    stk_pnrt = -1;
}
/*data_mem::~data_mem(){
	delete[] memory;
 }*/
int data_mem::load_word(int addr){
    return memory[addr];
}
void data_mem::store_word(int addr, int val){
    memory[addr] = val;
}

void data_mem::push_to_stack(int val){
    stack[++stk_pnrt] = val;
}

int data_mem::pop_from_stack(){
    return stack[stk_pnrt--];
}

bool data_mem::stack_is_empty(){
    return(stk_pnrt==-1);
}

bool data_mem::stack_is_full(){
    return(stk_pnrt==3);
    
}