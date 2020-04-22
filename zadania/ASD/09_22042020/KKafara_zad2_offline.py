# K. Kafara

"""
	Skrócony opis:
    Jeżeli istnieje ścieżka s -> t to ten modyfikowany  dfs puszczony z wierzchołka s nią przejdzie dokładnie raz. (tak dla każdej ścieżki)
    Jeżeli trafiamy na wierzchołek t, to sprawdzamy czy wyznaczona ścieżka jest równa (co do długości) dotychczas znanej
        jeżeli tak to zwiększamy licznik
        jeżeli nie to sprawdzamy czy nowa jest krótsza
            jeżeli tak to resteujemy licznik na 1 i uaktualniamy długość najkrótszej znanej ścieżki
            jeżeli nie: kończymy przetwarzanie wierzchołka
"""

# symbolizuje nieskończoność
inf = 1000000


def count_shortest_paths( G, s, t ):
    # dfs
    #############################################
    def dfs_sol(v, curr_path_len):
        # przegladamy sasiadow v
        for i in range(n):
            # jeżeli istnieje krawędź (v, i) oraz jest sens przez nią przechodzić: 
            if G[v][i] == 1 and (curr_path_len < path_len[i] or t == i):
                # jeżeli sąsiadem jest nasz wierzchołek docelowy
                if t == i:
                    if curr_path_len + 1 == path_len[t] or path_len[t] == inf:
                        path_count[0] += 1
                        # dla przypadku gdy znajdujemy droge do wierzcholka po raz pierwszy
                        path_len[t] = curr_path_len + 1
                        # nie ma sensu iść dalej z obecnego wierzcholka, ścieżki mogą byc tylko dłuższe
                        break
                    elif curr_path_len + 1 < path_len[t]:
                        path_count[0] = 1
                        path_len[t] = curr_path_len + 1
                        # także nie ma sensu isć dalej
                        break
                        
                else:            
                    path_len[i] = curr_path_len + 1
                    dfs_sol(i, curr_path_len + 1)
                    
    #############################################

    n = len(G)

    path_len = [inf] * n
    path_len[s] = 0

    curr_path_len = 0
    # taki dziwny sposob, poniewaz dfs_sol nie widzial zwyklej zmiennej, a tablice tak (improwizacja)
    # w każdym razie path_count[0] jest zmienna przechowującą obecnie znaną ilość najkrótszych ścieżek
    path_count = [0]

    # wywolujemny sie tylko w wirzcholka startowego s
    dfs_sol(s, curr_path_len)

    #print(path_len)
    #print(path_count)

    return path_count[0]



if __name__ == '__main__':
    G = [[False, True, True, False],
        [False, False, True, True ],
        [False, False, False, True ],
        [False, False, False, False]]
    print( count_shortest_paths( G, 0, 3 ))
        
    




