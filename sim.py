import parser
from native import pipe_line
from parser import register_file, data_memory, pc
global inst_mem
global stall
global cycle
global pipe

def fill_inst_mem(code):
	#code = parser.get_file(file)
	code = parser.split_to_lines(code)

	global pipe
	global inst_mem
	global stall

	cycle = 1
	
	inst_mem = parser.fill_instr_mem(code)
	'Im not sure about the following line, the pipe_line constructor is supposed to take a pc pointer Im not sure how to do that'
	pipe = pipe_line.pipe_line(pc)
	
	ret = pipe.fetch(inst_mem.getInst(pc.get()))
	pipe.write()
	pipe.decode()
	pipe.execute()
	pipe.access()
	stall = pipe.upline()
	pc.increment()
	return (inst_mem is None)

def next_step():
	global inst_mem
	global stall
	global cycle
	'ret is False if the simulator did not fetch a new instruction but is still running'
	'ret is None if the simulator stopped running'
	'ret contains the name of the new instruction that was added to the pipeline otherwise'
	ret = False
	try:
		if not pipe.empty():
			if not stall:
				ret = pipe.fetch(inst_mem.getInst(pc.get()))
				pc.increment()
			pipe.write()
			pipe.decode()
			pipe.execute()
			pipe.access()
			stall = pipe.upline()
		else:
			ret = None
	except KeyError:
		pass
	return ret