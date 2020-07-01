# K. Kafara
class GraphAdjList:
    def __init__(self, size = 0):
        self.size = size
        self.graph = [[] for i in range(size)]
        
        class Vertex:
            pass


    class Edge:
        def __init__(self, end, weight = 1):
            self.end = end
            self.weight = weight


    def add_dir_edge(self, b, e):
        self.graph[b].append(self.Edge(e))

    def add_undir_edge(self, b, e):
        self.graph[b].append(self.Edge(e))
        self.graph[e].append(self.Edge(b))
        # TODO:  obliczanie na bieżąco indeksu pod którym znajduje się krawędź przeciwna
        # na liście drugiego końca krawędzi

    def printg(self):
        for i in range(self.size):
            print(i, end=":  ")
            for edge in self.graph[i]:
                print(edge.end, end=" ")
            
            print()
    
    def get_size(self):
        return self.size


    ###############################################################################
    def bfs(self, source):
        ''' Zwraca tablicę krotek (parent, distance_from_source) o rząd-grafu elementach.
            Jeżeli distance_from_source == -1 ==> nie isnieje połączenie pomiędzy wierzchołkiem
            źródłowym, a danym wierzchołkiem '''
        visited = [False] * self.size
        ret_arr = [(None, -1)] * self.size
        ret_arr[source] = (None, 0)
       
        # Kolejka python'owa się do niczego nie nadaje ==> implementacja tablicowa
        queue = [0] * self.size
        b, e = 0, 0
        queue[0] = source

        while b <= e:
            current_vertex = queue[b]
            b += 1
            visited[current_vertex] = True

            ########
            # Przetwarzanie wierzchołka

            ########

            for i in range(len(self.graph[current_vertex])):
                if visited[ self.graph[current_vertex][i].end ] == False:
                    ret_arr[ self.graph[current_vertex][i].end ] = (current_vertex, ret_arr[current_vertex][1] + self.graph[current_vertex][i].weight)
                    e += 1
                    queue[e] = self.graph[current_vertex][i].end

            # print(ret_arr)
        return ret_arr
    ###############################################################################

    ###############################################################################
    def dfs(self, source):
        pass
    ###############################################################################

if __name__ == '__main__':
    print("Cokolwiek")

    GRAPHSIZE = int(input())
    edges = int(input())

    g = GraphAdjList(GRAPHSIZE)

    for i in range(edges):
        b = int(input())
        e = int(input())
        g.add_dir_edge(b, e)
    
    g.printg()

    bfs_res = g.bfs(0)

    print(bfs_res)
    

