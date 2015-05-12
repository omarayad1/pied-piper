#include "pipe_line.h"

pipe_line::pipe_line(PC* pc_pntr){
    for(int i=0; i<5; i++)
        line[i] = NULL;
    bubble = false;
    pc = pc_pntr;
}

void pipe_line::fetch(instruction* inst){
    line[0] = inst;
    cout << line[0]->get_name() << " fetched!\n";
}

void pipe_line::decode(){
    bubble = false;
    if(line[1] != NULL)
        line[1]->decode();
}

void pipe_line::execute(){
    if(line[2] != NULL)
    {
        //forwarding logic
        int forwarded;
        if(line[2]->get_type() == 'r')
        {
            rtype* instr = dynamic_cast<rtype*> (line[2]);
            int rsr = instr->get_rs();
            int rtr = instr->get_rt();
            if(forward(rsr, forwarded) && !bubble)
            {
                instr->set_op1(forwarded);
                cout << instr->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
            }
            if(instr->get_name() != "JR" && forward(rtr, forwarded) && !bubble)
            {
                instr->set_op2(forwarded);
                cout << instr->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
            }
        }
        else if(line[2]->get_type() == 'i')
        {
            itype* insti = dynamic_cast<itype*> (line[2]);
            int rsi = insti->get_rs();
            int rti = insti->get_rt();
            if(forward(rsi, forwarded) && !bubble)
            {
                insti->set_op1(forwarded);
                cout << insti->get_name() << " has updated R[rs] to " << forwarded << " by forwarding!\n";
            }
            if(insti->get_name() == "BNE" && forward(rti, forwarded) && !bubble)
            {
                insti->set_op2(forwarded);
                cout << insti->get_name() << " has updated R[rt] to " << forwarded << " by forwarding!\n";
            }
        }
        
        line[2]->execute();
        if(pc->jumped())
        {
            flush();
            pc->unjump();
        }
    }
}

void pipe_line::access(){
    if(line[3] != NULL)
    {
        //store forwarding logic
        if(line[3]->get_name() == "STO")
        {
            itype* stor = dynamic_cast<itype*> (line[3]);
            int forwarded;			//forward =1 for sto
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

void pipe_line::write(){
    if(line[4] != NULL)
        line[4]->write();
}

bool pipe_line::empty(){
    return (line[0]==NULL && line[1]==NULL && line[2]==NULL && line[3]==NULL && line[4]==NULL);
}

bool pipe_line::upline(){
    swap(line[3], line[4]);
    if(!bubble)
    {
        swap(line[2], line[3]);
        swap(line[1], line[2]);
        swap(line[0], line[1]);
        delete line[0];
        line[0]=NULL;
    }
    else
    {
        delete line[3];
        line[3]=NULL;
    }
    return bubble;
}

bool pipe_line::forward(int rin, int& result){
    //check inst in mem access state
    if(forward2(rin, result, 3))
        return true;
    else				//check inst in write state
        if(forward2(rin, result, 4))
            return true;
    return false;
}

bool pipe_line::forward2(int& rin2, int& result2, int i){
    if(line[i] != NULL && line[i]->get_type() != 'j' && line[i]->get_type() != 'n' && line[i]->get_name() != "STO" && line[i]->get_name() != "BNE")
    {
        if(line[i]->get_type() == 'r')		//if the leading instruction is an r-type instruction
        {
            rtype* tempr = dynamic_cast<rtype*> (line[i]);
            if(rin2 == tempr->get_rd())			//if registers match
            {
                result2 = tempr->get_res();
                return true;
            }
        }
        else
        {
            itype* tempi = dynamic_cast<itype*> (line[i]);
            if(rin2 == tempi->get_rt())					//if the leading instruction is an i-type instruction
            {
                if(tempi->get_name() == "LOAD")			//if registers match
                    if(i==4)					//if the leading LOAD instruction is in the write stage
                        result2 = tempi->get_loaded();		//forward
                    else
                    {
                        bubble = true;					//stall
                        cout << "bubble bitches!\n";
                    }
                    else
                        result2 = tempi->get_res();
                return true;
            }
        }
    }
    return false;
}

void pipe_line::flush(){
    if(line[0] != NULL)
    {
        cout << line[0]->get_name() <<  " has been flushed from the pipeline!\n";
        delete line[0];
        line[0] = NULL;
    }
    if(line[1] != NULL)
    {
        cout << line[1]->get_name() << " has been flushed from the pipeline!\n";
        delete line[1];
        line[1] = NULL;
    }
}