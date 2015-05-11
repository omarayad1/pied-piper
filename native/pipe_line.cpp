//#include "pipe_line.h"
//
//void pipe_line::decode(){
//	if(line[1] != NULL)
//	{
//		line[1]->decode();
//			
//		//forwarding logic
//		int forwarded;
//		if(line[1]->get_type() == 'r')
//		{
//			rtype* instr = dynamic_cast<rtype*> (line[1]);
//			int rsr = instr->get_rs();
//			int rtr = instr->get_rt();
//			if(forward(rsr, forwarded))
//				instr->set_op1(forwarded);
//			if(forward(rtr, forwarded))
//				instr->set_op2(forwarded);
//		}
//		else if(line[1]->get_type() == 'i')
//		{
//			itype* insti = dynamic_cast<itype*> (line[1]);
//			int rsi = insti->get_rs();
//			if(forward(rsi, forwarded))
//				insti->set_op1(forwarded);
//		}
//		else
//		{
//			jtype* instj = dynamic_cast<jtype*> (line[1]);
//			if(instj->get_name() == "JR")
//			{
//				int rsj = instj->get_rs();
//				if(forward(rsj, forwarded))
//					instj->set_res(forwarded);
//			}
//		}
//	}
//}
//
//bool pipe_line::forward(int rin, int& result){
//	//check inst in execute state
//	if(forward2(rin, result, 2))
//		return true;
//	else				//check inst in access state
//		if(forward2(rin, result, 3));
//			return true;
//	return false;
//}
//
//bool pipe_line::forward2(int& rin2, int& result2, int i){
//	if(line[i] != NULL && line[i]->get_type() != 'j' && line[i]->get_name() != "STO")
//	{
//		if(line[i]->get_type() == 'r')
//		{
//			rtype* tempr = dynamic_cast<rtype*> (line[i]);
//			if(rin2 == tempr->get_rd())
//			{
//				result2 = tempr->get_res();
//				return true;
//			}
//		}
//		else
//		{
//			itype* tempi = dynamic_cast<itype*> (line[i]);
//			if(rin2 == tempi->get_rt())
//			{
//				result2 = tempi->get_res();
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//bool pipe_line::upline(){
//	/*if(line[1] != NULL && line[1]->get_name() == "LOAD" && line[0]->get_name() != "STO")*/
//	if(line[1] != NULL && line[1]->get_name() == "LOAD")
//		bubble = true;
//	else
//		bubble = false;
//	swap(line[3], line[4]);
//	swap(line[2], line[3]);
//	swap(line[1], line[2]);
//	if(!bubble)
//	{
//		swap(line[0], line[1]);
//		delete line[0];
//		line[0]=NULL;
//	}
//	else
//	{
//		delete line[1];
//		line[1]=NULL;
//	}
//	return bubble;
//}