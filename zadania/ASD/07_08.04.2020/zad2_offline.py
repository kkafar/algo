# K. Kafara


# G to lista list z informacją o istnieniu krawędzi
# G[i] to lista numerów wierzchołków, które są połączone
# krawędzią z wierzchołkiem i
# tu proszę umieścić swoją implementację
# elementarny test. Może wypisać np.
# [None, 0, 1, 2]
def DFS( G ):
    def DFS_aux(v):
        # oznaczamy v jako odwiedzonego
        visited[v] = True
        # przeglądamy wszystkich sąsiadów v
        for j in range(len(G[v])):
            # jeżeli któryś jest nieodwiedzony, to wywołujemy się na nim rekurencyjnie
            if visited[G[v][j]] == False:
                info[G[v][j]] = v   
                DFS_aux(G[v][j])

    
    # info[i] = indeks wierzchołka z którego przyszliśmy do wierzchołka i
    n = len(G)
    info = [None] * n
    visited = [False] * n

    # przeglądamy wszystkie wierzchołki, zaczynająć od tego o indeksie 0
    for i in range(n):
        # jeżeli wierzchołek jeszcze nie był odwiedzony
        if visited[i] == False:
            # to wywołujemy się na nim DFS'em
            DFS_aux(i)

    return info

    
if __name__ == '__main__': 
    G = [[1,2],[0,2,3],[3,1,0],[]]
    print( DFS(G) )


