import data

class Instruction(object):
	def __init__(self):
		self.type = 0
	def execute(self, reg1=None, reg2=None, reg3=None):
		pass


class Add(Instruction):
	def __init__(self):
		Instruction.__init__()
	def execute(self, reg1=None, reg2=None, reg3=None):
		reg1.value = reg2.value + reg3.value


class Addi(Instruction):
	def __init__(self):
		Instruction.__init__()

	def execute(self, reg1=None, reg2=None, imm=0):
		reg1.value = reg2.value + imm


class Xor(Instruction):
	def __init__(self):
		Instruction.__init__()

	def execute(self, reg1=None, reg2=None, reg3=None):
		reg1.value = reg2.value ^ reg3.value


class Lw(Instruction):
	def __init__(self):
		Instruction.__init__()

	def execute(self, reg1=None, reg2=None, offset=0):
		reg1 = data.segment[reg2+offset]


class Sw(Instruction):
	def __init__(self):
		Instruction.__init__()

	def execute(self, reg1=None, reg2=None, offset=0):
		data.segment[reg2+offset] = reg1


class Ble(Instruction):
	def __init__(self):
		Instruction.__init__()

	def execute()