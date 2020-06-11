# K. Kafara

# Opis rozwiązania na str. 4-5 "ASD, Z"

# W implementacji listowej grafu, testowanie czy jakaś krawędź istnieje jest niestety w czasie O(E) ==> algorytm oparty na tym pomyśle jest O(VE).
# Natmiast jeżelibyśmy użyli reprezentacji macierzowej, sprawdzanei czy krawędź istnieje byloby w czasie O(1), natomiast sortowanie topologiczne działałoby wolniej

# Trzeba dopowiedzeć: nie wiem czy jest to rozwiązanie optymalne.



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

    def isEdge(self, beg, end):
        for edge in self.graph[beg].edges:
            if edge.end == end:
                return True
        return False

    def solution(self):
        topo_order = self.toposort()
        for i in range(len(topo_order) - 1, 0, -1):
            if self.isEdge(topo_order[i], topo_order[i - 1]) == False:
                return None

        return topo_order


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
    
        topo_order = graph.solution()
    
        if topo_order is None:
            print("W DAG'u nie ma sciekzi Hamiltona")
    
        else:
            print("W DAG'u mamy sciezke Hamiltona")
            for i in range( len(topo_order) - 1, -1, -1):
                print(topo_order[i], end=' ')

            print()




if __name__ == '__main__':
    main()
        