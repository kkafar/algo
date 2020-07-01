# K. Kafara

""" Dijkstra na macierzowej reprezentacji grafu. Opis w kodzie """

# symbolizuje +inf
INF = 9999999999

class MinPriorityQueue:
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
        @brief Usuwa element z najmniejszym priorytetem z kolejki. '''
        self.size -= 1
        self.queue[0], self.queue[self.size] = self.queue[self.size], self.queue[0]
        self.heapify(0)

    def front(self):
        '''
        @brief Zwraca element z najwyższym priorytetem z kolejki. '''
        return self.queue[0].obj



class GraphAdjMatrix:
    def __init__(self, rank):
        self.rank = rank
        self.graph = [ [0] * rank for i in range(rank) ]
        self.weight = [ [-1] * rank for i in range(rank) ]


    def add_dir_edge(self, beg, end):
        self.graph[beg][end] = 1

    def add_undir_edge(self, beg, end, weight = 1):
        self.graph[beg][end] = self.graph[end][beg] = 1
        self.weight[beg][end] = self.weight[end][beg] = weight

    def remove_dir_edge(self, beg, end):
        self.graph[beg][end] = 0

    def remove_undir_edge(self, beg, end):
        self.graph[beg][end] = self.graph[end][beg] = 0

    def printg(self):
        for i in range(self.rank):
            print(self.graph[i])

    def dijkstra(self, s, t):
        """ Zwraca +∞ jeżeli ścieżka nie istnieje. Długość najkrótszej ścieżki wpp.  """
        # Na potrzeby relaksjacji
        distance_arr = [INF] * self.rank
        distance_arr[s] = 0 
        
        # Do odtworzenia ścieżki
        parent_arr = [-1] * self.rank

        q = MinPriorityQueue()

        # Dodajemy wierzchołek źródłowy odo kolejki, z dowolnym priorytetem, nie musi być 0
        q.push(s, 0)

        # Dopóki kolejka nie jest pusta... 
        while not q.is_empty():
            # Ściągamy wierzchołek z kolejki 
            current_vertex = q.front()
            q.pop()

            # Jeżeli ściągniętym wierzchołkiem jest wierzchołek docelowy tzn., że możemy zwrócić obliczone wartości
            # w tym momencie powinny być poprawnie wyznaczone (odpowiednie twierdzenie jest w notatkach, str. 26 ASD,W) 
            if current_vertex == t:
                return (distance_arr[t], parent_arr)
            
            else:
                # Przeglądamy wszystkich sąsiadów wierzchołka current_vertex i dokonujemy relaksacji każdej z krawędzi.
                # Jeżeli dokonaliśmy relaksacji, to dodajemy wierzchołek do kolejki z priorytetem równym długośći prowadzącej
                # do niego krawędzi. 
                for i in range(self.rank):
                    if self.graph[current_vertex][i] == 1:
                        distance = distance_arr[current_vertex] + self.weight[current_vertex][i]
                        if distance < distance_arr[i]:
                            distance_arr[i] = distance
                            parent_arr[i] = current_vertex
                            q.push(i, self.weight[current_vertex][i])

        return INF


def get_path(parent_arr, vertex):
    v = vertex
    path = []
    while parent_arr[v] != -1:
        path.append(v)
        v = parent_arr[v]

    path.reverse()
    return path



def main():
    with open('input_zad1.txt', 'r') as input_file:
        line = input_file.readline().strip('\n').split(' ')
        rank = int(line[0])
        size = int(line[1])
        
        graph = GraphAdjMatrix(rank)

        for i in range(size):
            line = input_file.readline().strip('\n').split(' ')
            beg = int(line[0])
            end = int(line[1])
            weight = int(line[2])

            graph.add_undir_edge(beg, end, weight)

    graph.printg()
    (min_path_len, parent) = graph.dijkstra(0, 9)
    print(min_path_len, parent)
    print(get_path(parent, 9))



if __name__ ==   '__main__':
    main()



