from native import XOR, add, addi, ble, bne, jal, jr, jump, load, slt, store

def get_file(path):
	code = open(path ,'r').read()
	return code


def split_to_lines(code):
	return code.split('\n')