# K. Kafara

'''
Rozw. (GL)
- Wykonać algorytm DFS śledząc czasy przetworzenia wierzchołków. O(V + E)
- Wykonać algorytm DFS z wierzchołka o największym czasie przetworzenia. O(V + E)
- Jeżeli uda się dowiedzić wszystkie wierzchołki to wyznaczyliśmy dobry początek. (Jest nim korzeń drugiego wywołania)

Czas: 2 * O(V + E) + O(V) == O(V + E)
                      ^ (na zerowanie pól visited w drugim przebiegu dfs'a / rezerwowanie tablicy w dfs)

Dlaczego to działa? 
Jeżeli w czasie wywołania DFS z jednego z wierzchołków natrafimy na 'dobry początek' - to w tym wywołaniu 
przeglądniemy graf do końca, ponieważ z 'dobrego początku' mamy dojście wszędzie - do każdego nieodwiedzonego jeszcze wierzchołka. 
Zatem jeżeli istnieje dobry początek, to znajduje się on w 'ostatnim' drzewie przeszukiwań DFS. 
Co więcej skoro z korzenia drzewa DFS doszliśmy do 'dobrego początku', to dobrym początkiem równie dobrze może być sam korzeń
(z założenia istnieje ścieżka 'dobry początek' -> korzeń, a przeglądając graf stwierdzamy, że istnieje korzeń -> 'dobry początek')
Korzeń ostatniego drzewa DFS ma największy czas przetworzenia (!) ==> jest to nasz kandydat na 'dobry początek'.  
Pozostaje to zweryfikować wykonując kolejne wykonanie algorytmu DFS na grafie z wytypowanego wierzchołka. Jeżeli uda nam się odwiedzić wszystkie
wierzchołki - to mammy wyznaczony 'dobry początek', wpp. takowy nie istnieje. 

O(V + E)

Poniżej implementacja. '''

class GraphAdjList:
    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight    
    
    class Vertex:
        def __init__(self):
            self.visited = False
            self.edges = []

    def __init__(self, rank = 0):
        self.rank = rank
        self.graph = [ self.Vertex() for i in range(rank) ]


    def reset_vertices(self):
        for i in range(self.rank):
            self.graph[i].visited = False
        
    def add_dir_edge(self, b, e):
        self.graph[b].edges.append(self.Edge(e))

    def printg(self):
        for i in range(self.rank):
            print(i, end=":  ")
            for edges in self.graph[i].edges:
                print(edges.end, end=" ")
            
            print()

######################################################################################################333
    def dobry_poczatek(self):
        # Potrzebujemy korzystać z algorytmu dfs, zatem implementujemy go najpierw.
        # Z wykonania dfs'a, musimy dowiedzieć się, jaki wierzchołek był przetworzony jako ostatni (czyli znaleźć korzeń ostatniego drzewa DFS)
        def __dfs(current_vertex):
            self.graph[current_vertex].visited = True

            for edge in self.graph[current_vertex].edges:
                if self.graph[edge.end].visited == False:
                    __dfs(edge.end)

        last_vertex = 0
        for vertex in range(self.rank):
            if self.graph[vertex].visited == False:
                __dfs(vertex)
                last_vertex = vertex

    
        # Teraz wywołujemy się z potencjalnego 'dobrego początku' i sprawdzamy czy jednym wywołaniem DFS zdołamy odwiedzić wszystkie wierzchołki w grafie (
        # zliczamy ilośc wywołań DFS, jeżeli ma być więcej niż 1, to przerywamy działanie funkcji, bo nie ma po co sprawdzać dalej.)
        # Ale najpierw musimy zresetować graf. (tablicę odwiedziń)

        for vertex in range(self.rank):
            self.graph[vertex].visited = False
        
        __dfs(last_vertex)

        for vertex in range(self.rank):
            if self.graph[vertex].visited == False:
                return None

        return last_vertex
######################################################################################################333



def main():
    with open('input_zad5.txt', 'r') as input_file:
        line = input_file.readline().strip('\n').split(' ')
        rank = int(line[0])
        size = int(line[1])

        graph = GraphAdjList(rank)

        for line in range(size):
            line = input_file.readline().strip('\n').split(' ')
            beg = int(line[0])
            end = int(line[1])

            graph.add_dir_edge(beg, end)

    graph.printg()

    print(graph.dobry_poczatek())



if __name__ == '__main__':
    main()
        
