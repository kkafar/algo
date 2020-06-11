# K. Kafara


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
        def __init__(self, end):
            self.end = end
    
    class Vertex:
        def __init__(self):
            self.visited = False
            self.parent = None
            self.timein = 0
            self.low = 0
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]
        self.time = 0


    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
            self.graph[i].parent = None
        
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))

    # Sciągamy komentarz gdy rozważamy graf nieskierowany
    def add_undir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))
        self.graph[e].edges.append(self.Edge(b))
        # TODO:  obliczanie na bieżąco indeksu pod którym znajduje się krawędź przeciwna
        # na liście drugiego końca krawędzi

    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print(edges.end, end=" ")
            
            print()

    def find_bridges(self):
        def _dfs(vertex):
            # print("Wchodze na {}, time={}".format(vertex, self.time)) 
            self.graph[vertex].visited = True
            self.graph[vertex].timein = self.time
            self.graph[vertex].low = self.time
            self.time += 1

            for edge in self.graph[vertex].edges:
                # print("Z {} (timein={}, low={}) patrze na: {} (timein={}, low={})".format(vertex, self.graph[vertex].timein, self.graph[vertex].low, edge.end, self.graph[edge.end].timein, self.graph[edge.end].low))
                # Jeżeli nie jest to krawędź wsteczna, to idziemy dalej
                if self.graph[edge.end].visited == False:
                    self.graph[edge.end].parent = vertex
                    _dfs(edge.end)
                    # jeżeli wróciliśmy z niższej instancji to aktualizujemy low
                    if self.graph[vertex].low > self.graph[edge.end].low:
                        self.graph[vertex].low = self.graph[edge.end].low

                # Natomiast jeżeli jest to krawędź wsteczna
                
                elif edge.end != self.graph[vertex].parent and self.graph[vertex].low > self.graph[edge.end].low:
                    # print("Aktualizuje {}.low: {} --> {}".format(vertex, self.graph[vertex].low, self.graph[edge.end].low))
                    self.graph[vertex].low = self.graph[edge.end].low

            # Jeżeli spełniony jest warunek vertex.timein == vertex.low to znaczy że krawędź {vertex.parent, vertex} jest mostem (udowodnione z notatkach z wykładu, str. 33)
            if  self.graph[vertex].timein == self.graph[vertex].low:
                # Musimy wykluczyć ten jeden przypadek, żeby nie stwierdzić, że mostem jest krawędź której w grafie oczywiscie nie ma
                if self.graph[vertex].parent != -1:
                    bridges_list.append( (vertex, self.graph[vertex].parent) )
                    # print("Stwierdzam most {} {}".format(vertex, self.graph[vertex].parent))

            # print("Opuszczam {}, timein={}, low={}, parent={}".format(vertex, self.graph[vertex].timein, self.graph[vertex].low, self.graph[vertex].parent))


        bridges_list = []

        for i in range(self.rank):
            if self.graph[i].visited == False:
                # -1 oznacza, że jest to korzeń drzewa przeszukiwań dfs
                self.graph[i].parent = -1
                _dfs(i)

        return bridges_list



def main():
    with open('input_zad3.txt', 'r') as input_file:
        rank = int(input_file.readline())
        size = int(input_file.readline())
    
        graph = GraphAdjList(rank)
        
        for i in range(size):
            line = input_file.readline().strip('\n').split(' ')
            beg = int(line[0])
            end = int(line[1])
            graph.add_undir_edge(beg, end)


    graph.printg()

    bridges_list = graph.find_bridges()

    print("Lista krawedzi bedacych mostami")
    print(bridges_list)


if __name__ == '__main__':
    main()