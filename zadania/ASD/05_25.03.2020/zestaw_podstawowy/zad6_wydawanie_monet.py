# K. Kafara

# z6c5 wydawanie monet
INF = 10000 # symbolizuje +∞

def solution(M, k):
    F = [0] * (k + 1) # będziemy przechowywać kwoty od 0 do k
    
    for i in range(k + 1):
        MIN = INF
        for j in range (len(M)):
            if i >= M[j] and F[i - M[j]] < MIN:
                MIN = F[i - M[j]]

        if MIN != INF:
            F[i] = MIN + 1

    return F[k]

if __name__ == '__main__':
    print(solution([1, 5, 8], 15))
