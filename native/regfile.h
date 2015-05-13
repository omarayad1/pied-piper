#ifndef REGFILE_H
#define REGFILE_H


class regfile
{
private:
    int file[32];		//an array of 16 ints where each integer represents a register in the file
public:
    regfile();
    void write_to_reg(int radd, int val);			//writes value to the addressed register
    int load_from_reg(int radd);				//loads values from the addressed regiser
};

#endif