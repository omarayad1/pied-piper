#include "pipe_line.h"

pipe_line::pipe_line(PC* pc_pntr){
    for(int i=0; i<5; i++)				//initializes all pointers to NULL
        line[i] = NULL;
    bubble = false;
    pc = pc_pntr;
}

void pipe_line::fetch(instruction* inst){
    line[0] = inst;												//loads the instruction into the pipe line
    cout << line[0]->get_name() << " fetched!\n";
}

void pipe_line::decode(){
    bubble = false;									//resets the bubble variable to false each decode
    if(line[1] != NULL)
        line[1]->decode();							//if there's an isntruction in the decode stage its decoded
}

void pipe_line::execute(){
    if(line[2] != NULL)
    {
        //forwarding logic
        int forwarded;
        if(line[2]->get_type() == 'r')				//if the current instruction is an r-type isntruction
        {
            rtype* instr = dynamic_cast<rtype*> (line[2]);
            int rsr = instr->get_rs();				//rs and rt are extracted to be compared to the leading isntructions
            int rtr = instr->get_rt();
            if(forward(rsr, forwarded) && !bubble)			//a function tha contains the forwarding logic and returns true if regs are found
            {												//searching for rs first
                instr->set_op1(forwarded);			//if found the operands are updated
                cout << instr->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
            }
            if(instr->get_name() != "JR" && forward(rtr, forwarded) && !bubble)			//then searching for rt
            {
                instr->set_op2(forwarded);
                cout << instr->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
            }
        }
        else if(line[2]->get_type() == 'i')				//if the instruction is an i-type instruction
        {
            itype* insti = dynamic_cast<itype*> (line[2]);
            int rsi = insti->get_rs();					//getting the rs and rt to compare them with the leading instruction in the pipe line
            int rti = insti->get_rt();
            if(forward(rsi, forwarded) && !bubble)		//checking rs
            {
                insti->set_op1(forwarded);			//updating the operand
                cout << insti->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
            }
            if(insti->get_name() == "BNE" && forward(rti, forwarded) && !bubble)		//checking rt only if the instruction is a BNE
            {
                insti->set_op2(forwarded);			//updating the operand
                cout << insti->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
            }
        }
        
        line[2]->execute();						//if there's an instruction in the execute stage it's executed
        if(pc->jumped())					//if the instruction executed carries out a jump or a branch then the pipe line is flushed
        {
            flush();						//the pipe line flushes the instructions in the decode and fetch stages
            pc->unjump();					//resets the jump variable to false in the pc class
        }
    }
}

void pipe_line::access(){
    if(line[3] != NULL)
    {
        if(line[3]->get_name() == "SW")				//if the instruction in the mem access stage is SW it can carry out forwarding
        {
            itype* stor = dynamic_cast<itype*> (line[3]);
            int forwarded;
            int rstor = stor->get_rt();
            if(forward2(rstor, forwarded, 4))			//checks if the wanted registers are found in the instruction in the write back stage
            {
                stor->set_load(forwarded);			//if yes the result is forwarded
                cout << stor->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
            }
        }
        
        line[3]->access();					//if there's an instruction in the mem access stage it accesses the data memory
    }
}

void pipe_line::write(){

    if(line[4] != NULL)						//if there's an instruction in the write back stage it writes to the register file
        line[4]->write();
}

bool pipe_line::empty(){
    return (line[0]==NULL && line[1]==NULL && line[2]==NULL && line[3]==NULL && line[4]==NULL);		//returns true if all stages are empty
}

bool pipe_line::upline(){
    swap(line[3], line[4]);						//the instruction in the mem access stage to the write back stage
    if(!bubble)							//if the pipe line is not bubbling
    {
        swap(line[2], line[3]);			//each instruction is moved forward one stage
        swap(line[1], line[2]);
        swap(line[0], line[1]);
        delete line[0];					//the isntruction which was in the write back stage is removed from the pipe line and destroyed
        line[0]=NULL;
    }
    else
    {
        delete line[3];					//the isntruction which was in the write back stage is removed from the pipe line and destroyed
        line[3]=NULL;
    }
    cout << endl;
    return bubble;
}

bool pipe_line::forward(int rin, int& result){
    if(forward2(rin, result, 3))		//check if the register searched for is in the isntruction in the mem access stage
        return true;
    else				//if its not found in the mem access stage write back stage is checked
        if(forward2(rin, result, 4))
            return true;
    return false;
}

bool pipe_line::forward2(int& rin2, int& result2, int i){
    if(line[i] != NULL && line[i]->get_type() != 'j' && line[i]->get_type() != 'n' && line[i]->get_name() != "SW" && line[i]->get_name() != "BNE")
    {						//checking the instruction in the wanted stage only if it's not a j-type, SW, BNE, END or RET
        if(line[i]->get_type() == 'r')		//if the wanted instruction is an r-type instruction
        {
            rtype* tempr = dynamic_cast<rtype*> (line[i]);
            if(rin2 == tempr->get_rd())			//if registers match
            {
                result2 = tempr->get_res();			//result is returned through result variable and true is returned
                return true;
            }
        }
        else
        {
            itype* tempi = dynamic_cast<itype*> (line[i]);
            if(rin2 == tempi->get_rt())					//if the leading instruction is an i-type instruction
            {
                if(tempi->get_name() == "LW")			//if registers match
                    if(i==4)					//if the wanted instruction is a load instruction in the write back stage
                        result2 = tempi->get_loaded();		//result is forwarded normally
                    else
                    {									//else the bubbling occurs in the pipe line for one cycle
                        bubble = true;					//stall
                        cout << "bubble!\n";
                    }
                    else
                        result2 = tempi->get_res();			//if it's not a load instruction result is forwarded normally
                return true;
            }
        }
    }
    else if(line[i] != NULL && line[i]->get_name() == "JAL")			//if the leading instruction in the pipeline is a JAL
    {
        jtype* tempj = dynamic_cast<jtype*> (line[i]);
        if(rin2 == 15)			//if register is return address register (r15)
        {
            result2 = tempj->get_ret();			//return address is returned through forwarding
            return true;
        }
    }
    return false;
}

void pipe_line::flush(){
    if(line[0] != NULL)					//if there's an instruction in the fetch stage its removed from the pipe line and destroyed
    {
        cout << line[0]->get_name() <<  " has been flushed from the pipeline!\n";
        delete line[0];
        line[0] = NULL;
    }
    if(line[1] != NULL)					//if there's an instruction in the fetch stage its removed from the pipe line and destroyed
    {
        cout << line[1]->get_name() << " has been flushed from the pipeline!\n";
        delete line[1];
        line[1] = NULL;
    }
}