#include "PC.h"

PC::PC(){
    counter = 0x00400000;
    jump = false;
}
int PC::get(){
    return counter;
}
void PC::increment(){
    counter+=4;
}
void PC::load(int add){
    counter = add;              //loads a new pc and sets the jump flag to false
    jump = true;
}
bool PC::jumped(){
    return jump;
}
void PC::unjump(){
    jump = false;
    
}