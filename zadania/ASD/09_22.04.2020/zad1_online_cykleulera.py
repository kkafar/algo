def euler_cycle(G):
    def dfs(v):
        for i in range(arr[v], len(G), 1):
            arr[v] = i + 1
            if G[v][i] == 1:
                G[v][i] = 0
                G[i][v] = 0
                dfs(i)
            
        print(v)
    # G[i][j] = 1 -> G[i][j] = 0
    
    arr = [0] * len(G)
    dfs(0)
    
        
