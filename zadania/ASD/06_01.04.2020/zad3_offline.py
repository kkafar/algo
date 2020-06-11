# K. Kafara

def knapsack(A, k):
    # B[i] = (wartość_przedmiotu_na_jednostkę_masy, indeks_pod_którym_przedmiot_znajduje_się_w_tabicy_A)
    B = []
    for i in range( len(A) ):
        B.append( ( A[i][0] / A[i][1], i ) )

    # domyślnie sortujemy po pierwszej wartości każdej pary (czyli po wartości przedmiotu na jednostkę masy), ale chcemy
    # mieć posortowane od największej wartośći ==> reverse=True
    B.sort(reverse=True)

    value = 0
    mass = 0
    # dopóki możemy, to bierzemy całe przedmioty o kolejnych, największych wartościach (w stosunku do ich masy)
    i = 0
    while mass + A[ B[i][1] ][1] <= k:
        value += A[ B[i][1] ][0]
        mass += A[ B[i][1] ][1]
        i += 1

    # wzięliśmy tyle całych rzeczy ile mogliśmy, teraz ułamek ostatniej rzeczy która się nie zmieściła w całości
    # (o ile jest miejsce w plecaku)

    if mass < k:
        # (wartość/kg) * (tyle kg ile możemy zabrać)
        value += B[i][0] * (k - mass) 

    return value


if __name__ == '__main__':
    print( knapsack( [ (1,1), (10,2), (6,3) ], 3 ) )
