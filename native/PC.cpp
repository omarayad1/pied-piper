#include "PC.h"

PC::PC(){
    counter = 0;
    jump = false;
}
int PC::get(){
    return counter;
}
void PC::increment(){
    counter++;
}
void PC::load(int add){
    counter = add;
    jump = true;
}
bool PC::jumped(){
    return jump;
}
void PC::unjump(){
    jump = false;
    
}