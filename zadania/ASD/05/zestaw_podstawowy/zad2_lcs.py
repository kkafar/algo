# K. Kafara

# Najdłuższy wspólny podciąg (Longest Common Subsequence)
  
"""
    Zgodnie z założeniami w zadaniu zakładamy, że len(A) == len(B), ale gdyby tak nie było
    to wystarczy przeindeksować pętle i algorytm powienien działać poprawnie
"""

def solution(A, B):
    n = len(A)

    f = []

    for i in range(n + 1):
        f.append([0] * (n + 1))

    # f[i][j] - długość najdłuższego wspólnego podciągu ciągów A[0 … i - 1] oraz B[0 … j - 1]

    # jeżeli jeden z podciąŋów jest pusty, to oczywiście LCS == 0
    for i in range(n + 1):
        f[0][i] = 0
        f[i][0] = 0

    for i in range(1, n + 1, 1):
        for j in range(1, n + 1, 1):
            if A[i-1] >= B[j-1]:
                f[i][j] = f[i - 1][j - 1] + 1
            elif f[i - 1][j] >= f[i][j - 1]:
                f[i][j] = f[i - 1][j]
            else:
                f[i][j] = f[i][j - 1]
    
    return f[n][n]


if __name__ == '__main__':
    A = [1, 2, 3, 9]
    B = [1, 3, 9, 6]
    print(solution(A, B))
