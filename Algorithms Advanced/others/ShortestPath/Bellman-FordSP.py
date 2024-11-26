# Bellman-Ford Algorithm (Single Source, Handles Negative Weights)
def bellman_ford(source, nodes, edges):
    dist = [float('inf')] * nodes
    dist[source] = 0

    for _ in range(nodes - 1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            print("Graph contains a negative weight cycle")
            return

    for i in range(nodes):
        print(f"Distance from {source} to {i} is {dist[i]}")

# Example
nodes = 5
edges = [
    (0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
bellman_ford(0, nodes, edges)
