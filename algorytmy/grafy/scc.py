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


INF = 9999999 # symbolizuje +nieskończoność
class GraphAdjList:
    class Edge:
        def __init__(self, end):
            self.end = end   
    
    class Vertex:
        def __init__(self):
            # DFS
            self.visited = False
            ##################################################
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]

    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
        
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))

    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print(edges.end, end=" ")
            
            print()


    def scc(self):
        ''' @return tablica z numerami silnych spójnych składowych do których należą poszczególne wierzchołki '''
        def _dfs(current_vertex, rev_graph = None, scc_id = 0):
            '''
            @param rev_graph None - jeżeli przechodzimy właściwy graf'''
            if rev_graph is None:
                self.graph[current_vertex].visited = True

                for i in range( len( self.graph[current_vertex].edges ) ):
                    if self.graph[ self.graph[current_vertex].edges[i].end ].visited == False:
                        _dfs(self.graph[current_vertex].edges[i].end)

                queue.push(current_vertex)
            else:
                rev_graph.graph[current_vertex].visited = True
                scc_table[current_vertex] = scc_id
                for i in range( len(rev_graph.graph[current_vertex].edges) ):
                    if rev_graph.graph[ rev_graph.graph[current_vertex].edges[i].end ].visited == False:
                        _dfs(rev_graph.graph[current_vertex].edges[i].end, rev_graph, scc_id)

        queue = ArrQueue(self.rank)
        for i in range(self.rank):  
            if self.graph[i].visited == False:
                _dfs(i)

        # tworzymy nowy graf z odróconymi krawędziami
        reversed_graph = GraphAdjList(self.rank)
        for i in range(self.rank):
            for j in range(len(self.graph[i].edges)):
                reversed_graph.add_dir_edge(self.graph[i].edges[j].end, i)

        scc_table = [i for i in range(self.rank)]
        scc_id = 0

        while queue.is_empty() == False:
            current_vertex = queue.front()
            queue.pop()
            if reversed_graph.graph[current_vertex].visited == False:
                _dfs(current_vertex, reversed_graph, scc_id)
                scc_id += 1

        return scc_table


if __name__ == '__main__':
    rank = int(input())
    size = int(input())

    graph = GraphAdjList(rank)

    for i in range(size):
        b = int(input("B == "))
        e = int(input("E == "))
        graph.add_dir_edge(b, e)

    graph.printg()

    scc_table = graph.scc()
    print(scc_table) 
