from native import XOR, add, addi, ble, bne, jal, jr, jump, load, slt, store, regfile
from re import compile


def get_file(path):
	code = open(path ,'r').read()
	return code


def get_text_segment(code):
	data = code.split('.text')
	return data[-1]


def split_to_lines(code):
	data = code.split('\n')
	return [x.strip() for x in data]


def map_to_classes(line):
	
	rtype = compile(r"([a-zA-Z]+)\s+\$([0-9]+)\s*,\s*\$([0-9]+)\s*,\s*\$([0-9]+)")
	itype = compile(r"([a-zA-Z]+)\s+\$([0-9]+)\s*,\s*\$([0-9]+)\s*,\s*([0-9]+)")
	mem_instr = compile(r"(lw|sw)\s+\$([0-9]+)\s*,\s*([0-9]+)\s*\(\s*\$([0-9]+)\s*\)")
	jr = compile(r"(jr)\s+\$([0-9]+)")
	j_jal = compile(r"(j|jal)\s+([0-9]+)")


	if rtype.findall(line) != []:
		inst, reg1, reg2, reg3 = rtype.findall(line)[0]
	elif itype.findall(line) != []:
		inst, reg1, reg2, imm = itype.findall(line)[0]
	elif mem_instr.findall(line) != []:
		inst, reg1, imm, reg2 = mem_instr.findall(line)[0]
	elif jr.findall(line) != []:
		inst, reg1 = jr.findall(line)[0]
	elif j_jal.findall(line) != []:
		inst, imm = j_jal.findall(line)[0]
	else:
		inst = "UKW"
	return inst