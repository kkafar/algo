# K. Kafara

class GraphAdjList:
    def __init__(self, size = 0):
        self.size = size
        self.graph = [[] for i in range(size)]
        
    class Vertex:
        pass

    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight


    def add_dir_edge(self, b, e):
        self.graph[b].append(self.Edge(e))

    def add_undir_edge(self, b, e):
        self.graph[b].append(self.Edge(e))
        self.graph[e].append(self.Edge(b))
        # TODO:  obliczanie na bieżąco indeksu pod którym znajduje się krawędź przeciwna
        # na liście drugiego końca krawędzi

    def printg(self):
        for i in range(self.size):
            print(i, end=":  ")
            for edge in self.graph[i]:
                print(edge.end, end=" ")
            
            print()
        


if __name__ == '__main__':
    print("Cokolwiek")

    GRAPHSIZE = int(input())
    edges = int(input())

    g = GraphAdjList(GRAPHSIZE)

    for i in range(edges):
        b = int(input())
        e = int(input())
        g.add_dir_edge(b, e)
    
    g.printg()

