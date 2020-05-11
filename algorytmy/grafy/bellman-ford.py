# K. Kafara

# symbolizuje +inf
INF = 999999999 
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
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight
    
    class Vertex:
        def __init__(self):
            self.visited = False
            # opcjonalnie jeżeli chcemy odtwarzać ścieżkę, a nie tylko znać jej długość
            self.parent = None
            self.distance = INF
            self.edges = []

    def __init__(self, rank = 0, size = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]
        self.size = size


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

    def bellman_ford(self, source):
        ''' @brief Algorytm Bellmana-Forda najkrótszych ścieżek dla grafu nieskierowanego (dla skierowanego
        algorytm jest zasadniczo identyczny, trzeba po prostu inaczej krawędzie wczytać)\n 
        Jest problem implementacyjny: Tutaj 2 wewnętrzne pętle wykonują się V * E razy ==> O(V * V * E) a nie O(V * E)\n
        Rozwiązujemy ten problem tworząc sobie tablicę krawędzi'''

        self.graph[source].distance = 0

        edge_list = []
        for i in range(self.rank):
            for j in range(len(self.graph[i].edges)):
                edge_list.append((i, self.graph[i].edges[j].end, self.graph[i].edges[j].weight))
        
        print(len(edge_list))

        # V razy dokonujemy relaksacji każdej z E krwędzi
        for i in range(self.rank):  
            for j in range(len(edge_list)): 
                edge_list[j][2] 
                #print(type(edge_list[j][2]))
                #print(edge_list[j][2])
                # jaki sposób tam jest błąd!?!?!? Typy się zgadzają TODO!!!!
                distance = self.graph[edge_list[j][0]].distance + edge_list[j][2]
                if self.graph[edge_list[j][1]].distance > distance:
                    self.graph[edge_list[j][1]].distance = distance

        # Weryfikacja
        for i in range(self.size):
            if self.graph[edge_list[i][1]].distance > self.graph[edge_list[i][0]].distance + edge_list[i][2]:
                # to oznacza, że mamy w grafie ujemny cykl
                return False
        
        # w tablicy wierzchołków mamy poprawne wyniki
        for i in range(self.rank):
            print(self.graph[i].distance, end=' ')
        return True
        

if __name__ == '__main__':
    with open('input_file.txt', 'r') as input_file:
        rank = int(input_file.readline())
        size = int(input_file.readline())
        graph = GraphAdjList(rank, size)
        for i in range(size):
            b = int(input_file.readline())
            e = int(input_file.readline())
            graph.add_undir_edge(b, e)

    graph.printg() 
    graph.bellman_ford(0)
    
