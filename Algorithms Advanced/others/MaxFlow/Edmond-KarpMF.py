from collections import deque

def bfs(s, t, parent, capacity, adj):
    parent[:] = [-1] * len(parent)
    queue = deque([s])
    parent[s] = s

    while queue:
        u = queue.popleft()

        for v in adj[u]:
            if parent[v] == -1 and capacity[u][v] > 0:
                parent[v] = u
                if v == t:
                    return True
                queue.append(v)

    return False

def edmonds_karp(n, s, t, capacity):
    adj = {i: [] for i in range(n)}
    for u in range(n):
        for v in range(n):
            if capacity[u][v] > 0:
                adj[u].append(v)
                adj[v].append(u)

    parent = [-1] * n
    max_flow = 0

    while bfs(s, t, parent, capacity, adj):
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
print("Maximum Flow:", edmonds_karp(n, 0, 5, capacity))
