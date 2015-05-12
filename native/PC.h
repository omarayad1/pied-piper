#ifndef PC_H
#define PC_H

class PC
{
private:
    int counter;
    bool jump;
public:
    PC();
    int get();
    void increment();
    void load(int add);
    bool jumped();
    void unjump();
};

#endif