class InstMem(object):
	def __init__(self):
		self.mem = {}
		self.last = 0x00400000
	
	def addInst(self,instruction):
		self.mem[self.last] = instruction
		self.last += 4

	def getInst(self, address):
		return self.mem[address]