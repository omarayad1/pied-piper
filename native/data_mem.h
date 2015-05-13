#ifndef DATA_MEM_H
#define DATA_MEM_H

class data_mem
{
private:
    int memory[32];                 // memory container
    int stack[4];                   // stack container
    int stk_pnrt;                   // stack pointer
public:
    data_mem();
    int load_word(int addr);        // returns memory contents of the nwated address
    void store_word(int addr, int val);     // stores the val in the wanted memory address
    void push_to_stack(int);        // pushes a value to the stack structure
    int pop_from_stack();           // pops a value from the stack structure
    bool stack_is_empty();          //returns true if the stack empty
    bool stack_is_full();           //returns true if the stack is full
};

#endif