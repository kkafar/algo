class GraphAdjMatrix:
	def __init__(self, size):
		self.size = size
		self.graph = [ [0] * size for i in range(size) ] 

	def add_dir_edge(self, beg, end):
		self.graph[beg][end] = 1

	def add_undir_edge(self, beg, end):
		self.graph[beg][end] = self.graph[end][beg] = 1

	def remove_dir_edge(self, beg, end):
		self.graph[beg][end] = 0

	def remove_undir_edge(self, beg, end):
		self.graph[beg][end] = self.graph[end][beg] = 0

	def printg(self):
		for i in range(self.size):
			print(self.graph[i])
