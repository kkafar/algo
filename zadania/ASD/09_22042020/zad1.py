# K. Kafara

import inspect


""" Opis, dowód poprawności str. 1-2 "ASD,Z" """

class GraphAdjMatrix:
	'''
	@brief Reprezentacja grafu poprzez listę sąsiedztwa\n
	Dostępne metody: add_dir_edge(beg, end)\n,
	add_undir_edge(beg, end)\n,
	remove_dir_edge(beg, end)\n, 
	remove_undir_edge(beg, end)\n, 
	printg() '''

	def __init__(self, rank):
		self.rank = rank
		self.graph = [ [0] * rank for i in range(rank) ] 


	def add_dir_edge(self, beg, end):
		self.graph[beg][end] = 1


	def add_undir_edge(self, beg, end):
		self.graph[beg][end] = self.graph[end][beg] = 1


	def remove_dir_edge(self, beg, end):
		self.graph[beg][end] = 0


	def remove_undir_edge(self, beg, end):
		self.graph[beg][end] = self.graph[end][beg] = 0


	def printg(self):
		for i in range(self.rank):
			print(self.graph[i])


	def find_euler_cycle(self):
		# do przeprowadzenie algorytmu potrzebujemy mieć informację o każdej z krawędzi.
		# Jeżeli nie chcielibyśmy psuć grafu, to potrzebna jest nam dodatkowa informacja nt każdej z krawędzi. (Czy już nią przechodziliśmy)
		# Tutaj niszczymy graf

		# Tworzymy sobie dodatkową tablicę, dla każdego wierzchołka, od której krawędzi musimy sprawdzać (wcześniejsze już były sprawdzone)
		checked = [0] * self.rank

		# zaczynamy od 0
		euler_cycle = []

		def _fec(vertex):
			for i in range (checked[vertex], self.rank):
				checked[vertex] = i + 1
				if self.graph[vertex][i] == 1:
					self.graph[vertex][i] = self.graph[i][vertex] = 0
					_fec(i)

			euler_cycle.append(vertex)
	
		_fec(0)

		return euler_cycle




if __name__ == '__main__':
	with open('input_zad1.txt', 'r') as input_file:
		rank = int(input_file.readline())			
		size = int(input_file.readline())
		graph = GraphAdjMatrix(rank)
		for i in range(size):
			beg = int(input_file.readline())
			end = int(input_file.readline())
			graph.add_undir_edge(beg, end)

	graph.printg()

	euler_cycle = graph.find_euler_cycle()

	print(euler_cycle)
