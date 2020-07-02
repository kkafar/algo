# K. Kafara

# K. Kafara


""" Algorytm Bellmana-Forda na macierzowej reprezentacji grafu.
Złożoność tego algorytmu wynosi O(V * E), ponieważ (V - 1)-krotnie relaksujemy każdą z E krawędzi.

Przypomnijmy że jest to algorytym obliczający najkrótsze ścieżki z źródła do wszystkich pozostałych wierchołków
w grafie.

Graf może być dowolny (*). Wagi krawędzi dowolne. Algorytm ma możliwość wykrywania ujemnych cykli.
(*) - ale szczerze mówiąc w przypadku grafu nieskierowanego, tak rzucając tylko okiem, nie wiem czy do listy krawędzi,
które będziemy relaksować dodawać obydwie krawędzie (u, v), (v, u) czy tylko jedną z nich.


Idea jest prosta:
Zakładamy, że dystans od źródła do każdego z wierzchołków wynosi +∞. Odległość źródło-źródło wynosi 0. 
(V - 1)-krotnie dokonujemy relaksacji każdej z E krawędzi.
Następnie dokonujemy weryfikacji (sprawdzając czy dla każdej krawędzi (u,v) (nie musi być skierowana) zachodzi:
obecnie znana odległość od źródła wierzchołka v ≤ obecnie znanej odległości od źródła wierzchołka u + waga krawędzi (u,v) )
Jeżeli dla choć jednego wierzchołka nie jest to prawda ==> w grafie mamy ujemny cykl. Wpp w tablicy wynikowej powinniśmy mieć 
prawidłowe rezultaty.  

Oczywiście jeżeli ścieżki istnieją, to możemy nie tylko znać ich długości ale także przez tablicę rodziców mamy możliwość 
odtworzenia tych ścieżek.  """

INF = 99999999      # symbolizuje +∞

class GraphAdjMatrix:
    def __init__(self, rank):
        self.rank = rank
        self.graph = [ [0] * rank for _ in range(rank) ] 
        # Będziemy tworzyć listę krawędzi od razu podczas tworzenia grafu. Inaczej należy to robić dopiero wewnątrz
        # funkcji bellman_ford(…)
        self.edges = []

    class Edge:
        def __init__(self, b, e, w):
            self.b = b
            self.e = e
            self.w = w

    def add_dir_edge(self, beg, end, weight):
        self.graph[beg][end] = 1
        self.edges.append(self.Edge(beg, end, weight))

    def add_undir_edge(self, beg, end, weight = 1):
        self.graph[beg][end] = self.graph[end][beg] = 1
        # Na razie dodajemy obydwie krawędzie skierowane składające się na krawędź nieskierowaną
        self.edges.append(self.Edge(beg, end, weight))
        self.egdes.append(self.Edge(end, beg, weight))


    def remove_dir_edge(self, beg, end):
        self.graph[beg][end] = 0


    def remove_undir_edge(self, beg, end):
        self.graph[beg][end] = self.graph[end][beg] = 0


    def printg(self):
        for i in range(self.rank):
            print(self.graph[i])

    def relax(self, edge, distance_arr, parent_arr):
        distance = distance_arr[edge.b] + edge.w
        if distance_arr[edge.e] > distance:
            distance_arr[edge.e] = distance
            parent_arr[edge.e] = edge.b
    
    def bellman_ford(self, s):
        # ZWRACA -INF jeżeli istnieje cykl ujemny. Wpp tablicę distance_arr
        # Potrzebujemy tablicy rodziców oraz odległości
        parent_arr = [None] * self.rank
        distance_arr = [INF] * self.rank
        distance_arr[s] = 0

        # Relaksujemy V-1 razy każdą z E (2* dla grafu nieskierowanego (???)) krawędzi. 
        for _ in range(self.rank - 1):
            for edge in self.edges:
                self.relax(edge, distance_arr, parent_arr)


        # Sprawdzamy nie nie ma cyklu ujemnego
        for edge in self.edges:
            if distance_arr[edge.e] > distance_arr[edge.b] + edge.w:
                return -INF

        return distance_arr
        
