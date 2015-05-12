#include "PC.h"

PC::PC(){
	counter = 0;
}
int PC::get(){
	return counter;
}
void PC::increment(){
	counter++;
}
void PC::load(int add){
	counter = add;
}