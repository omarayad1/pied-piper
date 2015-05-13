import parser
from native import pipe_line
from parser import register_file, data_memory, pc

inst_mem = 0
counter = 0
stall=False
cycle=1
pipe=0

def fill_inst_mem(file):
	code = parser.get_file(file)
	code = parser.split_to_lines(code)

	global data
	global pipe
	inst_mem = parser.fill_instr_mem(code)
	'Im not sure about the following line, the pipe_line constructor is supposed to take a pc pointer Im not sure how to do that'
	pipe = pipe_line.pipe_line(pc)
	return (inst_mem is None)

def next_step():
	global data
	global counter
	global stall
	global cycle
	'ret is False if the simulator did not fetch a new instruction but is still running'
	'ret is None if the simulator stopped running'
	'ret contains the name of the new instruction that was added to the pipeline otherwise'
	ret = False

	if !pipe.empty():
		if !stall:
			ret = pipe.fetch(inst_mem.getInst(pc.get()))
		pipe.write()
        pipe.decode()
        pipe.execute()
        pipe.access()
        stall = pipe.upline()
    else:
    	ret = None

    return ret