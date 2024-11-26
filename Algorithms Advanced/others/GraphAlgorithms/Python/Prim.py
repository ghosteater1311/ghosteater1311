import heapq

def prims(nodes, adj):
    key = [float('inf')] * nodes
    parent = [-1] * nodes
    inMST = [False] * nodes
    key[0] = 0

    pq = [(0, 0)]

    while pq:
        _, u = heapq.heappop(pq)
        inMST[u] = True

        for v, weight in adj[u]:
            if not inMST[v] and weight < key[v]:
                key[v] = weight
                heapq.heappush(pq, (key[v], v))
                parent[v] = u

    for i in range(1, nodes):
        print(f"{parent[i]} - {i}")

# Example
nodes = 5
adj = {
    0: [(1, 2), (3, 6)],
    1: [(0, 2), (2, 3), (3, 8), (4, 5)],
    2: [(1, 3), (4, 7)],
    3: [(0, 6), (1, 8)],
    4: [(1, 5), (2, 7)]
}
prims(nodes, adj)
