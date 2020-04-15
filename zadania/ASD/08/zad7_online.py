# Zakładam, że graf jest w postaci listy sąsiedztwa, przy czym elementy tablicy dla i-tego wierzchołka to pary uporządkowane
# (indeks_sasiada, pulap_tunelu_powietrznego)

def solution(Graph, x, y, t, t0):
    # x - wierzchołek startowy
    # y - wierzchołek końcowy
    # t - tolerancja pułapu
    # t0 - pułap startowy

    n = len(Graph)
    # kolejka i zmienne do jej obsługi
    queue = [None] * n
    b = 0
    e = 0

    # tablica odwiedzin
    visited = [False] * n

    # dodajemy wierzchołek startowy do kolejki
    queue[0] = x

    # przrobimy no najwyżej n wierzchołków, wiec kolejka się nie zapętli
    while b <= e:
        # pobieramy wierzchołek z kolejki 
        curr_vertex = queue[b]
        b += 1
        visited[curr_vertex] = True

        # przeglądamy sąsiadów wierchołka curr_vertex
        for i in range(len(Graph[curr_vertex])):
            if visited[Graph[curr_vertex][i][0]] == False and t0 >= Graph[curr_vertex][i][1] - t and \
                t0 <= Graph[curr_vertex][i][1] + t

                if Graph[curr_vertex][i][0] == y: 
                    return True

                else:
                    # w przeciwnym wypadku dodajemy wierzchołek do kolejki, aby podróżować dalej
                    e += 1
                    queue[e] = Graph[curr_vertex][i][0]
            
            # w przeciwym wypadku (wierzchołek był odwiedzony bądź nie mieścimy się w toleracji pułapu)
            # nie robimy nic - poczucamy tą/ę scieżkę.

    return False

# Jak teraz patrzę, to można by także robić to dfs'em, stosując to samo kryterium porzucania ścieżki
# Asymptotycznie złożoność powinna być taka sama, bo może się zdarzyć sytuacja że będziemy musieli przeszukać
# dfs'em wszystko


