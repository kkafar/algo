# K. Kafara

class ArrQueue:
	'''
	FIFO\n
	Jako argument konstruktora przyjmuje rozmiar kolejki\n
	Dostepne metody: is_empty(), push(), pop(), front() '''
	def __init__(self, size):
		self.size = size
		self.current_size = 0
		self.queue = [0] * size
		self.beg = 0
		self.end = -1

	def is_empty(self):
		''' 
		@return True - jeżeli rozmiar kolejki wynosi 0\n
		@return False - jeżeli rozmiar kolejki != 0 '''
		if self.current_size == 0: 	
			return True
		else: 						
			return False

	def push(self, value):
		''' 
		@brief Dodaje element o kluczu @param value na koniec kolejki. \n
		@warning procedura nie sprawdza czy nie następuje nadpisanie innego elementku kolejki 
		(koniec kolejki obliczany jest modulo rozmiar_kolejki ==> nigdy nie nastąpi próba zapisu poza
		zarezerwowana pamięcią.) '''
		self.current_size += 1
		self.end = (self.end + 1) % self.size
		self.queue[self.end] = value

	def pop(self):
		'''
		@brief Usuwa pierwszy element z kolejki. '''
		self.current_size -= 1
		self.beg = (self.beg + 1) % self.size

	def front(self):
		'''
		@brief Zwraca pierwszy element z kolejki.\n
		@warning Funkcja nie sprawdza poprawności operacji (czy np. nie próbujemy ściągnąć z pustej kolejki).'''
		return self.queue[self.beg]	



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
        def __init__(self, end, weight = 1, rev = -1):
            self.end = end
            self.weight = weight    
            # Dla krawędzi nieskierowanej (indeks krawędzi przeciwnie skierowanej na liście wierzchołka 'end'):
            self.rev = rev
    
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


    def add_undir_edge(self, b, e, weight):
        self.graph[b].edges.append(self.Edge(e, weight, len(self.graph[e].edges)))
        self.graph[e].edges.append(self.Edge(b, weight, len(self.graph[b].edges) - 1))
        

    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print(edges.end, end=" ")
            
            print()

    def dfs(self, source):
        ''' Od razu wrapper, gdyby chcież wywoływać dfs'a na całym grafie (nie np. tylko na jednej spójnej (silnie) składowej ) '''
        def _dfs(current_vertex):
            self.graph[current_vertex].visited = True
            for i in range( len( self.graph[current_vertex].edges ) ):
                if self.graph[ self.graph[current_vertex].edges[i].end ].visited == False:
                    self.graph[ self.graph[current_vertex].edges[i].end ].parent = current_vertex
                    _dfs(self.graph[current_vertex].edges[i].end)

        _dfs(source)

    def bfs(self, source):
        queue = ArrQueue(self.rank)
        queue.push(source)
    
        while queue.is_empty() == False:
            current_vertex = queue.front()
            queue.pop()
            self.graph[current_vertex].visited = True

            for i in range( len( self.graph[current_vertex].edges ) ):
                if self.graph[ self.graph[current_vertex].edges[i].end ].visited == False:
                    self.graph[ self.graph[current_vertex].edges[i].end ].parent = current_vertex
                    queue.push(self.graph[current_vertex].edges[i].end)
