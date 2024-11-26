# Dijkstra's Algorithm (Single Source, Non-negative Weights)
import heapq

def dijkstra(source, nodes, adj):
    dist = [float('inf')] * nodes
    dist[source] = 0
    pq = [(0, source)]  # Priority queue as (distance, node)

    while pq:
        current_dist, u = heapq.heappop(pq)

        for v, weight in adj[u]:
            if current_dist + weight < dist[v]:
                dist[v] = current_dist + weight
                heapq.heappush(pq, (dist[v], v))

    for i in range(nodes):
        print(f"Distance from {source} to {i} is {dist[i]}")

# Example
nodes = 5
adj = {
    0: [(1, 10), (4, 3)],
    1: [(2, 2)],
    2: [(3, 9)],
    3: [],
    4: [(1, 1), (2, 8)]
}
dijkstra(0, nodes, adj)
