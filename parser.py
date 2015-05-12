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
	inst, reg1, reg2, reg3 = compile(r"([a-zA-Z]+)\s+\$([0-9]+)\s*,\s*\$([0-9]+)\s*,\s*\$([0-9]+)")[0]
	
