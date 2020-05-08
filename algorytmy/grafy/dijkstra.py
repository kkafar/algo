# K. Kafara

class MinPriorityQueue:
    '''
    @brief Kolejka priotrytetowa (MIN). Realizwana za pomocą "Pythonowej" listy. 
    @method push(obj, prior)
    @method pop()
    @method front()
    @method is_empty() '''
    class QueueElement:
        def __init__(self, obj, prior):
            self.obj = obj
            self.prior = prior

    def __init__(self):
        self.size = 0
        self.queue = []

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def push(self, obj, prior):
        '''
        @brief Dodajem objekt @param obj do kolejki z priorytetem @param prior '''
        index = self.size
        # jeżeli jest wymagane poszerzenie listy
        if self.size == len(self.queue):
            self.size += 1
            self.queue.append(self.QueueElement(obj, prior))

        # jeżeli nie trzeba poszerzać listy (ponieważ usunęliśmy jakies elmenty i jest miejsce)
        else:
            self.size += 1
            self.queue[index].obj = obj
            self.queue[index].prior = prior

        while self.parent(index) >= 0 and self.queue[ self.parent(index) ].prior > prior:
            self.queue[ self.parent(index) ], self.queue[index] = self.queue[index], self.queue[ self.parent(index) ]
            index = self.parent(index)


    def print(self):
        for i in range(self.size):
            print("(obj={}, prior={})".format(self.queue[i].obj, self.queue[i].prior), end=' ')
        print()

    def is_empty(self):
        if self.size == 0: return True
        else: return False
    
    def heapify(self, i):
        largest = i
        while i < self.size:
            left = self.left(i)
            right = self.right(i)

            if left < self.size and self.queue[left].prior < self.queue[largest].prior:
                largest = left
            
            if right < self.size and self.queue[right].prior < self.queue[largest].prior:
                largest = right

            if largest != i:
                self.queue[i], self.queue[largest] = self.queue[largest], self.queue[i]
                i = largest
            
            else:
                break


    def pop(self):
        '''
        @brief Usuwa element z najwyższym priorytetem z kolejki. '''
        self.size -= 1
        self.queue[0], self.queue[self.size] = self.queue[self.size], self.queue[0]
        self.heapify(0)

    def front(self):
        '''
        @brief Zwraca element z najwyższym priorytetem z kolejki. '''
        return self.queue[0].obj


INF = 9999999 # symbolizuje +nieskończoność
class GraphAdjList:
    '''
    @brief Reprezentacja grafu poprzez listę sąsiedztwa. Konstrucja podobna do tej stosowanej w cpp. \n
    Dostępne metody: add_dir_edges, add_undir_edges, printg, dfs, bfs, reset_vertices\n
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
            self.distance = INF
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]


    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
            self.graph[i].parent = -1
        
    def add_dir_edge(self, b, e, w):
        self.graph[b].edges.append(self.Edge(e, w))

    # Sciągamy komentarz gdy rozważamy graf nieskierowany
    '''def add_undir_edges(self, b, e):
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

    def dijkstra(self, source):
        '''
        Wersja 1-wszyscy'''
        p_queue = MinPriorityQueue()
        p_queue.push(source, 0)
        self.graph[source].distance = 0

        while p_queue.is_empty() == False:
            current_vertex = p_queue.front()
            p_queue.pop()

            self.graph[current_vertex].visited = True

            for i in range(len(self.graph[current_vertex].edges)):
                edge_end = self.graph[current_vertex].edges[i].end

                if self.graph[edge_end].visited == False:
                    distance = self.graph[current_vertex].distance + self.graph[current_vertex].edges[i].weight
                    
                    if self.graph[edge_end].distance > distance:
                        self.graph[edge_end].distance = distance

                    p_queue.push(edge_end, self.graph[edge_end].distance)


if __name__ == '__main__':
    rank = int(input())
    size = int(input())

    graph = GraphAdjList(rank)

    for i in range(size):
        b = int(input("B == "))
        e = int(input("E == "))
        w = float(input("W == "))
        graph.add_dir_edge(b, e, w)

    graph.printg()
    graph.dijkstra(0)

    print(graph.graph[rank - 1].distance)



