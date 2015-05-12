import parser
from native import pipe_line

def fill_inst_mem(file):
	code = parser.get_file(file)
	code = parser.split_to_lines(code)

	data = parser.fill_instr_mem(code)

