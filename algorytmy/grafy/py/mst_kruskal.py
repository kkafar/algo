# K. Kafara

class Node:
    def __init__(self):
        #self.key = key
        self.parent = self
        self.rank = 0

def find_set(x):
    if x != x.parent:
        x.parent = find_set(x.parent)
    return x.parent

def union(x, y):
    x = find_set(x)
    y = find_set(y)
    if x.rank > y.rank:
        y.parent = x
    else:
        x.parent = y
        if x.rank == y.rank:
            y.rank += 1

def make_set():
    return Node()

def edge_comp(edge):
    return edge.weight

class GraphAdjList:
    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight    
    
    class Vertex:
        def __init__(self):
            self.edges = []
            self.set = None

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]
        self.edge_list = []

    '''
    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
            self.graph[i].parent = -1'''
    '''    
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))'''

    def add_undir_edge(self, b, e, w):
        self.graph[b].edges.append(self.Edge(e, w))
        self.graph[e].edges.append(self.Edge(b, w))
        self.edge_list.append((b, e, w))
        # TODO:  obliczanie na bieżąco indeksu pod którym znajduje się krawędź przeciwna
        # na liście drugiego końca krawędzi

    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print('({}, {})'.format(edges.end, edges.weight), end=" ")
            
            print()
    
    def mst_kruskal(self):
        self.edge_list.sort(key=lambda e: e[2])
        mst = []
        for i in range(self.rank):
            self.graph[i].set = make_set()

        for edge in self.edge_list:
            if find_set(self.graph[edge[0]].set) != find_set(self.graph[edge[1]].set):
                mst.append(edge)
                union(self.graph[edge[0]].set, self.graph[edge[1]].set)

        return mst



if __name__ == '__main__':
    with open('input_file.txt', 'r') as input_file:
        rank = int(input_file.readline())
        size = int(input_file.readline())
        graph = GraphAdjList(rank)
        for i in range(size):
            b = int(input_file.readline())
            e = int(input_file.readline())
            w = int(input_file.readline())
            graph.add_undir_edge(b, e, w)

    graph.printg()
    mst = graph.mst_kruskal()
    print(mst)
    
