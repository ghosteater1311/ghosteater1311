def dfs(s, t, visited, parent, capacity, adj):
    visited[s] = True
    if s == t:
        return True

    for v in adj[s]:
        if not visited[v] and capacity[s][v] > 0:
            parent[v] = s
            if dfs(v, t, visited, parent, capacity, adj):
                return True
    return False

def ford_fulkerson(n, s, t, capacity):
    adj = {i: [] for i in range(n)}
    for u in range(n):
        for v in range(n):
            if capacity[u][v] > 0:
                adj[u].append(v)
                adj[v].append(u)

    parent = [-1] * n
    max_flow = 0

    while True:
        visited = [False] * n
        if not dfs(s, t, visited, parent, capacity, adj):
            break

        path_flow = float('Inf')
        v = t
        while v != s:
            u = parent[v]
            path_flow = min(path_flow, capacity[u][v])
            v = u

        v = t
        while v != s:
            u = parent[v]
            capacity[u][v] -= path_flow
            capacity[v][u] += path_flow
            v = u

        max_flow += path_flow

    return max_flow

# Example
n = 6
capacity = [
    [0, 16, 13, 0, 0, 0],
    [0, 0, 10, 12, 0, 0],
    [0, 4, 0, 0, 14, 0],
    [0, 0, 9, 0, 0, 20],
    [0, 0, 0, 7, 0, 4],
    [0, 0, 0, 0, 0, 0]
]
print("Maximum Flow:", ford_fulkerson(n, 0, 5, capacity))
