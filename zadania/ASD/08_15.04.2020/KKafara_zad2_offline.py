# K. Kafara

# from pprint import pprint

def knapsack2d( P, max_w, max_h ):
    # idea rozwiązania całkowicie analogiczna do standardowego dyskretnego problemu plecakowego
    
    # zakładamy tablicę 3D
    # A[i][w][h] = maksymalna wartość jaką można uzyskać rozważając przedmioty od 0 do i, nie przekraczając wagi w ani wysokości h
    n = len(P)
    A = []
    for i in range(n):
        A.append([])
        for j in range(max_w + 1):
            A[i].append([])
            for k in range(max_h + 1):
                A[i][j].append(0)

    # pprint(A)
    
    # w tym miejscu "cały szcześcian" jest wypełniony zerami. Teraz uzupełniamy wartości
    # dla ściany stojącej na weirszu o numerze 0 (nad A[0][0] mają zostać 0 ==> iterujemy od 1)
    for w in range(1, max_w + 1):
        for h in range(1, max_h + 1):
            if w >= P[0][1] and h >= P[0][2]:
                A[0][w][h] = P[0][0]
            # w przeciwnym wypadku zostaje 0

    
    for i in range(1, n):
        for w in range(max_w + 1):
            for h in range(max_h + 1):
                if w >= P[i][1] and h >= P[i][2] and A[i - 1][w - P[i][1]][h - P[i][2]] + P[i][0] > A[i - 1][w][h]:
                    A[i][w][h] = A[i - 1][w - P[i][1]][h - P[i][2]] + P[i][0]
                else:
                    A[i][w][h] = A[i - 1][w][h]

    return A[n - 1][max_w][max_h]


if __name__ == '__main__':
    P = [(5,10,3), (7,8,12), (2,7,3)]
    print( knapsack2d( P, 16, 15 )) # wypisze 9
