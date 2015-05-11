from re import compile

def split_to_lines(code):
	return code.split('\n')

def split_data(code):
	inst_segment = {}
	pc = 0x00400000
	inst_regex = compile("""
		([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*(\$[a-zA-Z][0-9])
		|(syscall)
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*([0-9]*)
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*(\$[a-zA-Z][0-9]))
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*([0-9])\s*(\(\$[a-zA-Z][0-9]\))
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*([0-9]*)
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])
		|([a-zA-Z0-9]+)\s*([a-zA-Z0-9_]*)
		|([a-zA-Z0-9]+)\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*(\$[a-zA-Z][0-9])\s*[\s|,]\s*([a-zA-Z0-9_]*)
		""")
	for line in code:
		inst_segment[pc] = inst_regex.findall(line)
		pc+=4
	return inst_segment

