# K. Kafara


""" Rozwiązanie opieramy na zmodyfikowanym algorytmie BFS. 
    Idąc do wierzchołka t, chcemy przejść po możliwe minimalnej liczbie krawędzi
    o koszcie 1 ==> wychodząc z wierzchołka v sprawdzamy najpierw możliwej ścieżki
    prowadzącej przez sąsiadów do których koszt wyonosi 0, a dopiero w dalszej kolejnośći 
    wyruszamy ścieżkami których koszt z obecnego wierzchołka wynosi 1 """


# Do odwiedzania wierzchołków w odpowiedniej kolejności wykorzystamy kolejkę z możliwością 
# dodawania elementów na początek i koniec

class Edge:
    def __init__(self, ver):
        self.vertex = ver
        # self.cost = c
        self.next = None
        self.prev = None


class Queue:
    def __init__(self):
        self.beg = None
        self.end = None


    def push_front(self, ver):
        new_el = Edge(ver)

        # dodajemy pierwszy element do kolejki 
        if self.beg is None and self.end is None: 
            self.beg = new_el
            self.end = new_el

        else: 
            new_el.next = self.beg
            self.beg.prev = new_el
            self.beg = new_el
    
    def push_back(self, ver):
        new_el = Edge(ver)

        # dodajemy pierwszy element do kolejki
        if self.beg is None and self.end is None: 
            self.beg = new_el
            self.end = new_el

        else:
            new_el.prev = self.end
            self.end.next = new_el
            self.end = new_el

    def is_empty(self):
        if self.beg is None:
            return True
        
        else:
            return False

    def pop_front(self):
        # zakłada że kolejka nie jest pusta!

        # gdy mamy tylko 1 element
        if self.beg == self.end:
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.end = None
            del tmp
            return (ver)
        
        else: 
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.beg.next
            self.beg.prev = None
            del tmp
            return (ver)

    def pop_back(self):
        # zakłada że kolejka nie jest pusta!

        # gdy mamy tylko 1 element
        if self.beg == self.end:
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.end = None
            del tmp
            return (ver)

        else:
            ver = self.end.vertex
            #cost = self.end.cost
            tmp = self.end
            self.end = self.end.prev
            self.end.next = None
            del tmp
            return (ver)


    def printq(self):
        tmp = self.beg
        while not (tmp is None):
            print("({})  ".format(tmp.vertex), end="")
            tmp = tmp.next
        # new line
        print()

inf = 10000000 # symbolizuje nieskończoność

def path_cost( graph, s, t ):
# policz koszt trasy
    n = len(graph)

    # tablica kosztow dojscia do poszczegolnych wierzcholkow
    cost = [inf] * n   
    
    # dwustronna kolejka do obsługi zmodyfikowanego BFS'a
    queue = Queue()
    cost[s] = 0
    queue.push_front(s)

    while not queue.is_empty():
        # pobieramy wierzcholek z poczatku kolejki 
        curr_vertex = queue.pop_front()

        # przegladamy kolejno wszystkich sasiadow curr_vertex. Jeżeli koszt obecnej ścieżki do sąsiada jest mniejszy niż dotychczas znany
        # to dodamy go do kolejki. 
        #   a) Jeżeli dojście do sąsiada kosztuje 0 to dodamy go na początek
        #   b) jeżeli dojście do sąsiada kosztuje 1 to dodamy go na koniec
        for i in range(0, len(graph[curr_vertex])):
            if cost[ graph[curr_vertex][i][0] ] > cost[curr_vertex] + graph[curr_vertex][i][1]:
                cost[ graph[curr_vertex][i][0] ] = cost[curr_vertex] + graph[curr_vertex][i][1]

                if graph[curr_vertex][i][1] == 0:
                    cost[graph[curr_vertex][i][0]] = cost[curr_vertex]
                    queue.push_front(graph[curr_vertex][i][0])
                
                else:
                    cost[graph[curr_vertex][i][0]] = cost[curr_vertex] + 1
                    queue.push_back(graph[curr_vertex][i][0])

    
    return cost[t]

        

if __name__ == '__main__':
    G = [[(1,0), (2,1)],\
        [(3,1), (2,0)],\
        [(3,0)],\
        []]

    # zwraca koszt dojscia do wierzcholka lub inf jezeli sciezka nie istnieje
    print( path_cost( G, 0, 3 ) )

    
    




