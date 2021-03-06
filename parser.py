from native import XOR, add, addi, ble, bne, jal, jr, jump, load, slt, store, regfile, data_mem, PC, ret, jmpro
from classes import inst_mem
from re import compile

register_file = regfile.regfile()
data_memory = data_mem.data_mem()
pc = PC.PC()

instr_map = {
	"XOR": XOR.XOR,
	"ADD": add.add,
	"ADDI": addi.addi,
	"BLE": ble.ble,
	"BNE": bne.bne,
	"JAL": jal.jal,
	"JR": jr.jr,
	"J": jump.j,
	"LW": load.lw,
	"SLT": slt.slt,
	"SW": store.sw,
	"JMPRO": jmpro.jmpro,
	"RET": ret.ret
	}

def get_file(path):
	code = open(path ,'r').read()
	return code


def split_to_lines(code):
	data = code.split('\n')
	return [x.strip() for x in data]


def map_to_class(line):

	rtype = compile(r"([a-zA-Z]+)\s+\$([0-9]+)\s*,\s*\$([0-9]+)\s*,\s*\$([0-9]+)")
	itype = compile(r"([a-zA-Z]+)\s+\$([0-9]+)\s*,\s*\$([0-9]+)\s*,\s*([0-9]+)")
	mem_instr = compile(r"(lw|sw)\s+\$([0-9]+)\s*,\s*([0-9]+)\s*\(\s*\$([0-9]+)\s*\)")
	jr = compile(r"(jr)\s+\$([0-9]+)")
	j_jal = compile(r"(j|jal|jmpro)\s+([0-9]+)")
	ret_c = compile(r"(ret)")

	if rtype.findall(line) != []:
		inst, reg1, reg2, reg3 = rtype.findall(line)[0]
		return instr_map[inst.upper()](int(reg1), int(reg2), int(reg3), register_file)

	elif itype.findall(line) != []:
		inst, reg1, reg2, imm = itype.findall(line)[0]
		if inst.upper() == "BNE":
			return instr_map[inst.upper()](int(reg1), int(reg2), int(imm), register_file, pc)
		elif  inst.upper() == "BLE":
			return instr_map[inst.upper()]()
		return instr_map[inst.upper()](int(reg1), int(reg2), int(imm), register_file)

	elif mem_instr.findall(line) != []:
		inst, reg1, imm, reg2 = mem_instr.findall(line)[0]
		return instr_map[inst.upper()](int(reg1), int(reg2), int(imm), register_file, data_memory)

	elif jr.findall(line) != []:
		inst, reg1 = jr.findall(line)[0]
		return instr_map[inst.upper()](int(reg1), register_file, pc)

	elif j_jal.findall(line) != []:
		inst, imm = j_jal.findall(line)[0]
		if inst.upper() == "J":
			return instr_map[inst.upper()](int(imm), pc)
		elif inst.upper() == "JMPRO":
			return instr_map[inst.upper()](int(imm), data_memory,pc)
		else:
			return instr_map[inst.upper()](int(imm), register_file, pc)
	elif ret_c.findall(line) != []:
		inst = ret_c.findall(line)[0]
		return instr_map[inst.upper()](data_memory, pc)
	else:
		inst = "UKW"


def fill_instr_mem(code):
	instruction_memory = inst_mem.InstMem()
	for line in code:
		instruction_memory.addInst(map_to_class(line))
	return instruction_memory