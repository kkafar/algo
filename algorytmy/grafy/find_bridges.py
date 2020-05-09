# K. Kafara

class GraphAdjList:
    '''
    @brief Reprezentacja grafu poprzez listę sąsiedztwa. Konstrucja podobna do tej stosowanej w cpp. \n
    Dostępne metody: add_dir_edges, add_undir_edges, printg, dfs, bfs\n
    Wskazówki:\n
    Odwołanie do i-tego sąsiada wierzchołka v: self.graph[ self.graph[v].edges[i].end ]\n
    Odwołanie się do pól wierzchołka v: self.graph[v].(pole)\n
    Odwołanie do pól krawędzi prowadzącej z v do i-tego sąsiada: self.graph[v].edges[i].(pole)\n
    Przed korzystaniem z kolejnych metod należy pamiętać o RESECIE ZMIENNYCH! (oczywiście jeżeli nie opuszczamy tego kroku celowo)
     '''

    class Edge:
        def __init__(self, end):
            self.end = end    
            self.is_bridge = False
    
    class Vertex:
        def __init__(self):
            self.visited = False
            self.time_in = None
            self.low = None
            self.parent = None
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]
        self.time = 0


    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
        
        
    '''def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))'''

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


    def find_bridges(self):
        def _dfs(source):
            self.graph[source].visited = True
            self.time += 1
            self.graph[source].time_in = self.time
            self.graph[source].low = self.time
            print('Odwiedzam wierzcholek: {}, parent: {}, time_in: {}, low: {}'.format(source, self.graph[source].parent, self.graph[source].time_in, self.graph[source].low))

            for v in range(len(self.graph[source].edges)):
                edge_end = self.graph[source].edges[v].end
                
                print('Patrze na wierzcholek {} z wierzcholka {}'.format(edge_end, source))
                
                if self.graph[edge_end].visited == False:
                    self.graph[edge_end].parent = source
                    _dfs(edge_end)
                    
                    # bierzemy minimum po low naszych dzieci
                    if self.graph[edge_end].low < self.graph[source].low:
                        self.graph[source].low = self.graph[edge_end].low

                # w przeciwnym wypadku oznacza to że znaleźliśmy krawędź wsteczną (o ile nie jest to nasz rodzic)
                elif edge_end != self.graph[source].parent and self.graph[source].low > self.graph[edge_end].low:
                    self.graph[source].low = self.graph[edge_end].low

            # wtedy krawędź {v, v.parent} jest mostem
            if self.graph[source].time_in == self.graph[source].low:
                print('[{}, {}] '.format(source, self.graph[source].parent))
            print('Opuszczam wierzcholek: {}, parent: {}, time_in: {}, low: {}'.format(source, self.graph[source].parent, self.graph[source].time_in, self.graph[source].low))

        for i in range(self.rank):
            if self.graph[i].visited == False:
                _dfs(i)
        
            


if __name__ == '__main__':
    rank = int(input())
    size = int(input())

    graph = GraphAdjList(rank)

    for i in range(size):
        b = int(input("B == "))
        e = int(input("E == "))
        graph.add_undir_edge(b, e)

    graph.printg() 
    graph.find_bridges()
