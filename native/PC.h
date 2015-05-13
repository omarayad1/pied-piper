#ifndef PC_H
#define PC_H
#include <iostream>
class PC
{
private:
    int counter;            //the counter
    bool jump;              //a flag which keeps track of whether the pc has jumped or not
public:
    PC();
    int get();              //returns the pc value
    void increment();       //increment the pc value
    void load(int add);     //loads the pc with a new value for branching and jumping
    bool jumped();          //returns true if the pc has just carried out jumping
    void unjump();          //resets the jump flag to false
};

#endif