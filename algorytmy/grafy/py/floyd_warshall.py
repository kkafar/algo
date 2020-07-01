# K. Kafara
from pprint import pprint
""" Algorytm Floyda-Warshalla
Wyznacza najkrótsze ścieżki pomiędzy każdą parą wierzchołków w grafie. 
Graf nieskierowany (skierowany też chyba może być), ważony (wagi krawędzi - dowolne liczby rzeczywiste), nie ma cykli ujemnych!

Krótki opis:
Operujemy na reprezentacji macierzowej.

Oznaczmy przez |V| ilość wierzchołkow w grafie.

Dla każdej pary u,v wierzchołków w grafie sprawdzamy czu nie opłaca się przechodzić przez wierzchołek t.
0 ≤ t < |V|

Jak łatwo widać po kodzie: mamy złożoność O(|V|^3)
"""

INF = 999999999

class GraphAdjMatrix:
    def __init__(self, size):
        self.size = size
        self.graph = [ [0] * size for _ in range(size) ] 
        self.distance_arr = [ [INF] * size for _ in range(size) ]


    def add_dir_edge(self, beg, end):
        self.graph[beg][end] = 1


    def add_undir_edge(self, beg, end, weight = 1):
        self.graph[beg][end] = self.graph[end][beg] = 1
        self.distance_arr[beg][end] = self.distance_arr[end][beg] = weight

    def remove_dir_edge(self, beg, end):
        self.graph[beg][end] = 0


    def remove_undir_edge(self, beg, end):
        self.graph[beg][end] = self.graph[end][beg] = 0


    def printg(self):
        for i in range(self.size):
            print(self.graph[i])


    def floyd_washall(self):
        # W macierzy wynikowej (odległości) mamy wagi tam gdzie istnieją bezpośrednie krawędzie oraz wartość INF
        # tam gdzie krawędzi nie ma. Pozostaje wyzerować przekątną:
        for i in range(self.size):
            self.distance_arr[i][i] = 0
            print(self.distance_arr[i])


        for t in range(self.size):
            for u in range(self.size):
                for v in range(self.size):
                    # Jeżeli odpowiednie krawędzie (ścieżki) istnieją
                    if self.distance_arr[u][t] != INF and self.distance_arr[t][v] != INF:
                        # Obliczamy długość trasy przechodzącej przez wierzchołek t
                        distance = self.distance_arr[u][t] + self.distance_arr[t][v]
                        # Jeżeli jest ona mniejsza niż dotychczas znana odległość wierzchołków u,v to podmieniamy (relaksacja)
                        if self.distance_arr[u][v] > distance:
                            self.distance_arr[u][v] = distance


        return self.distance_arr




def main():
    with open('test_floyd_warshall.txt', 'r') as input_file:
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
    
    graph.floyd_washall()

    for i in range(graph.size):
        for j in range(graph.size):
            if graph.distance_arr[i][j] != INF:
                print(graph.distance_arr[i][j], end=' ')

            else:
                print(0, end=' ')

        print()

    print(graph.distance_arr[0][9])

if __name__ == '__main__':
    main()


