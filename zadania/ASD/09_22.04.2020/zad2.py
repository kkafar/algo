# K. Kafara

from collections import deque 


class GraphAdjList:
    '''
    @brief Reprezentacja grafu poprzez listę sąsiedztwa. Konstrucja podobna do tej stosowanej w cpp. \n
    Dostępne metody: add_dir_edges, add_undir_edges, printg, dfs, bfs\n
    Wskazówki:\n
    Odwołanie do i-tego sąsiada wierzchołka v: self.graph[ self.graph[v].edges[i].end ]\n
    Odwołanie się do pól wierzchołka v: self.graph[v].(pole)\n
    Odwołanie do pól krawędzi prowadzącej z v do i-tego sąsiada: self.graph[v].edges[i].(pole)\n
    Przed korzystaniem z kolejnych metod należy pamiętać o RESECIE ZMIENNYCH! (oczywiście jeżeli nie opuszczamy tego kroku celowo) '''

    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight    
    
    class Vertex:
        def __init__(self):
            self.visited = False
            self.parent = -1
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]


    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
            self.graph[i].parent = -1
        
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))

    # Sciągamy komentarz gdy rozważamy graf nieskierowany
    '''def add_undir_edge(self, b, e):
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

    def toposort(self):
        def _dfs(v):
            self.graph[v].visited = True

            for edge in self.graph[v].edges:
                if self.graph[edge.end].visited == False:
                    _dfs(edge.end)

            queue.append(v)


        queue = []

        for i in range(self.rank):
            if self.graph[i].visited == False:
                _dfs(i)

        return queue


def main():
    with open('input_zad2.txt', 'r') as input_file:
    rank = int(input_file.readline())
    size = int(input_file.readline())

    graph = GraphAdjList(rank)
    
    for i in range(size):
        line = input_file.readline().strip('\n').split(' ')
        beg = int(line[0])
        end = int(line[1])
        graph.add_dir_edge(beg, end)


    graph.printg()

    toposorted = graph.toposort()

    print(toposorted)




if __name__ == '__main__':
    main()
        