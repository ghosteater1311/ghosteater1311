# 
import heapq

def prim(n, adj):
    mst_weight = 0
    visited = [False] * n
    min_heap = [(0, 0)]  # (weight, vertex)

    while min_heap:
        weight, u = heapq.heappop(min_heap)

        if visited[u]:
            continue
        visited[u] = True
        mst_weight += weight

        for v, w in adj[u]:
            if not visited[v]:
                heapq.heappush(min_heap, (w, v))

    return mst_weight

# Example
n = 4
adj = {
    0: [(1, 10), (2, 6), (3, 5)],
    1: [(0, 10), (3, 15)],
    2: [(0, 6), (3, 4)],
    3: [(0, 5), (1, 15), (2, 4)]
}
print("Minimum Spanning Tree weight:", prim(n, adj))
