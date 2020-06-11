# Rozwiązanie Jakuba Klimczaka

def szachownica(n, A):
    DP = [0] * n
    for i in range(n):
        DP[i] = [0] * n
    for i in range(n):
        for j in range(n):
            if i == 0 and j == 0:
                DP[i][j] = A[i][j]
            else:
                if i == 0:
                    DP[i][j] = DP[i][j-1] + A[i][j]
                elif j == 0:
                    DP[i][j] = DP[i-1][j] + A[i][j]
                else:
                    DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + A[i][j]
    return DP[n-1][n-1]
                

A = [[1, -1, 0, 2, -3], 
    [2, -3, 0, -1, 3], 
    [-4, -3, 2, 1, 2], 
    [2, 1, -5, -3, 1], 
    [-5, -3, 2, 1, 0]]

print(szachownica(5, A))