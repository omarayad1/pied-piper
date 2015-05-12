#ifndef REGFILE_H
#define REGFILE_H


class regfile
{
private:
	int file[32];
public:
	regfile();
	void write_to_reg(int radd, int val);
	int load_from_reg(int radd);
};

#endif