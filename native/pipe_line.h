#ifndef PIPELINE_H
#define PIPELINE_H

#include "rtype.h"
#include "itype.h"
#include "jtype.h"
#include <iostream>

class pipe_line{
private:
	instruction* line[5];
	bool bubble;
	
	bool forward(int rin, int& result){
		//check inst in execute state
		if(forward2(rin, result, 3))
			return true;
		else				//check inst in access state
			if(forward2(rin, result, 4))
				return true;
		return false;
	}
	
	bool forward2(int& rin2, int& result2, int i){
		if(line[i] != NULL && line[i]->get_type() != 'j' && line[i]->get_name() != "STO")
		{
			if(line[i]->get_type() == 'r')
			{
				rtype* tempr = dynamic_cast<rtype*> (line[i]);
				if(rin2 == tempr->get_rd())
				{
					result2 = tempr->get_res();
					return true;
				}
			}
			else
			{
				itype* tempi = dynamic_cast<itype*> (line[i]);
				if(rin2 == tempi->get_rt())
				{
					result2 = tempi->get_res();
					return true;
				}
			}
		}
		return false;
	}
public:
	pipe_line(){
		for(int i=0; i<5; i++)
			line[i] = NULL;
		bubble = false;
	}

	void fetch(instruction* inst){
		line[0] = inst;
		cout << line[0]->get_name() << " fetched!\n";
	}

	void decode(){
		if(line[1] != NULL)
			line[1]->decode();
	}

	void execute(){
		if(line[2] != NULL)
		{
			//forwarding logic
			int forwarded;
			if(line[2]->get_type() == 'r')
			{
				rtype* instr = dynamic_cast<rtype*> (line[2]);
				int rsr = instr->get_rs();
				int rtr = instr->get_rt();
				if(forward(rsr, forwarded))
				{
					instr->set_op1(forwarded);
					cout << instr->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
				}
				if(instr->get_name() != "JR" && forward(rtr, forwarded))
				{
					instr->set_op2(forwarded);
					cout << instr->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
				}
			}
			else if(line[2]->get_type() == 'i')
			{
				itype* insti = dynamic_cast<itype*> (line[2]);
				int rsi = insti->get_rs();
				if(forward(rsi, forwarded))
				{
					insti->set_op1(forwarded);
					cout << insti->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
				}
			}

			line[2]->execute();
		}
	}
	void access(){
		if(line[3] != NULL)
		{
			//store forwarding logic
			if(line[3]->get_name() == "STO")
			{
				itype* stor = dynamic_cast<itype*> (line[3]);
				int forwarded;
				int rstor = stor->get_rt();
				if(forward2(rstor, forwarded, 4))
				{
					stor->set_load(forwarded);
					cout << stor->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
				}
			}

			line[3]->access();
		}
	}
	void write(){
		if(line[4] != NULL)
			line[4]->write();
	}
	bool empty() {
		return (line[0]==NULL && line[1]==NULL && line[2]==NULL && line[3]==NULL && line[4]==NULL);
	}
	bool upline(){
		/*if(line[1] != NULL && line[1]->get_name() == "LOAD" && line[0]->get_name() != "STO")*/
		if(line[1] != NULL && line[1]->get_name() == "LOAD")
			bubble = true;
		else
			bubble = false;
		swap(line[3], line[4]);
		swap(line[2], line[3]);
		swap(line[1], line[2]);
		if(!bubble)
		{
			swap(line[0], line[1]);
			delete line[0];
			line[0]=NULL;
		}
		else
		{
			delete line[1];
			line[1]=NULL;
		}
		return bubble;
	}
};

#endif