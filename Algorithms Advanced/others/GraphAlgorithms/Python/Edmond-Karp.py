from collections import deque

def bfs(source, sink, residual, parent):
    visited = [False] * len(residual)
    queue = deque([source])
    visited[source] = True

    while queue:
        u = queue.popleft()
        for v in range(len(residual)):
            if not visited[v] and residual[u][v] > 0:
                parent[v] = u
                if v == sink:
                    return True
                visited[v] = True
                queue.append(v)
    return False

def edmond_karp(capacity, source, sink):
    nodes = len(capacity)
    residual = [row[:] for row in capacity]
    parent = [-1] * nodes
    max_flow = 0

    while bfs(source, sink, residual, parent):
        path_flow = float('inf')
        v = sink
        while v != source:
            u = parent[v]
            path_flow = min(path_flow, residual[u][v])
            v = parent[v]

        v = sink
        while v != source:
            u = parent[v]
            residual[u][v] -= path_flow
            residual[v][u] += path_flow
            v = parent[v]

        max_flow += path_flow

    return max_flow

# Example
capacity = [
    [0, 16, 13, 0, 0, 0],
    [0, 0, 10, 12, 0, 0],
    [0, 4, 0, 0, 14, 0],
    [0, 0, 9, 0, 0, 20],
    [0, 0, 0, 7, 0, 4],
    [0, 0, 0, 0, 0, 0]]
print("The maximum possible flow is", edmond_karp(capacity, 0, 5))
