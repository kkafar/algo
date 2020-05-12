# K. Kafara

from queue import Queue

# symbolizuje +inf
INF = 999999999 
class GraphAdjList:
    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight
    
    class Vertex:
        def __init__(self):
            self.visited = False
            self.time_in = 0
            self.time_out = 0
            self.edges = []

    def __init__(self, rank = 0, size = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]
        self.time = 0

    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
        
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))

    # Sciągamy komentarz gdy rozważamy graf nieskierowany
    def add_undir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))
        self.graph[e].edges.append(self.Edge(b))
        # TODO:  obliczanie na bieżąco indeksu pod którym znajduje się krawędź przeciwna
        # na liście drugiego końca krawędzi'''


    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print(edges.end, end=" ")
            
            print()

    def topo_sort(self):
        def _dfs(source):
            self.graph[source].visited = True
            
            for edge in self.graph[source].edges:
                if self.graph[edge.end].visited == False:
                    _dfs(edge.end)

            queue.put(source)
        
        queue = Queue()

        for i in range(self.rank):
            if self.graph[i].visited == False:
                _dfs(i)
                
        while queue.empty() == False:
            print(queue.get(), end=' ')



if __name__ == '__main__':
    with open('input_file.txt', 'r') as input_file:
        rank = int(input_file.readline())
        size = int(input_file.readline())
        graph = GraphAdjList(rank, size)
        for i in range(size):
            b = int(input_file.readline())
            e = int(input_file.readline())
            graph.add_dir_edge(b, e)

    graph.printg() 
    graph.topo_sort()
    
