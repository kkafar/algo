# K. Kafara

class ArrQueue:
	def __init__(self, size):
		self.size = size
		self.current_size = 0
		self.queue = [0] * size
		self.beg = 0
		self.end = -1

	def is_empty(self):
		if self.current_size == 0: 	
			return True
		else: 						
			return False

	def push(self, value):
		self.current_size += 1
		self.end = (self.end + 1) % self.size
		self.queue[self.end] = value

	def pop(self):
		self.current_size -= 1
		self.beg = (self.beg + 1) % self.size

	def front(self):
		return self.queue[self.beg]		
   
