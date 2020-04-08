# K. Kafara


# Ta implementacja przegląda tylko spójną składową grafu do której należy wierzchołek źródłowy (tylko te
# wierzchołki do których isnieje ścieżka z wierzchołka źródłowego)

def BFS( G, s ):
    # kolejka do zbierania kolejnych zadań (zadanie to numer wierzchołka który mamy odwiedzić)
    # n - elementowa kolejka wystarczy (n - liczba wierzchołków w grafie), gdyż każdy wierzchołek odwiedzamy
    # co najwyżej raz => tylko raz odpowiadające mu zadanie pojawi się w kolejce ==> kolejka n elem. wystarcza :) 
    n = len(G)
    queue = [None] * n
    # zmienne do obsługi kolejki
    b = 0
    e = 0

    # zakładamy też tablicę zgodnie z wymaganiami zadania
    
    info = [(None, -1)] * n
    # dodajemy startowy wierzchołek do kolejki i uzupełniamy dla niego informacje
    queue[e] = s
    info[s] = (None, 0)

    while b <= e:
        # pobieramy wierzchołek z kolejki 
        # print("Pobieram b: {}  key: {}".format(b, queue[b]))
        # print(info)
        curr_vertex = queue[b]
        b += 1

        # przeglądamy "curr_verex-ty" wiersz w poszukiwaniu sąsiadów obecnie przetwarzanego wierzchołka 
        # print("Sasiedzi {}".format(curr_vertex))
        for i in range(n):
            # jeżeli znajdziemy sąsiada i jest od nieodwiedzony (jego odległość wynosi -1)
            # print(G[curr_vertex], info[i][1])
            if G[curr_vertex][i] == 1 and info[i][1] == -1:
                # uzupełniamy dane dla sąsiada i dodajemy go na koniec kolejki 
                info[i] = (curr_vertex, info[curr_vertex][1] + 1)
                e += 1
                # print("Dodaje e: {}  key: {}".format(e, i))
                queue[e] = i;

    return info



if __name__ == '__main__': 
    G = [[0,1,1,0],\
         [0,0,0,1],\
         [0,1,0,1],\
         [0,0,0,0]]
         
    print( BFS(G,0) )

