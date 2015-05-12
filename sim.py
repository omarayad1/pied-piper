import parser
from native import pipe_line

code = parser.get_file('fixture/test2.asm')
code = parser.split_to_lines(code)

print parser.fill_instr_mem(code).mem