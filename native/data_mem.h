#ifndef DATA_MEM_H
#define DATA_MEM_H

class data_mem
{
private:
    int memory[32];
    int stack[4];
    int stk_pnrt;
public:
    data_mem();
    int load_word(int addr);
    void store_word(int addr, int val);
    void push_to_stack(int);
    int pop_from_stack();
    bool stack_is_empty();
    bool stack_is_full();
};

#endif