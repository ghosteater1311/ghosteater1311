import heapq

def dijkstra(start, adj, dist):
    pq = [(0, start)]
    dist[start] = 0

    while pq:
        d, node = heapq.heappop(pq)

        if d > dist[node]:
            continue

        for neighbor, weight in adj[node]:
            if dist[node] + weight < dist[neighbor]:
                dist[neighbor] = dist[node] + weight
                heapq.heappush(pq, (dist[neighbor], neighbor))

# Example
nodes = 5
adj = {0: [(1, 2), (4, 1)], 1: [(2, 3)], 4: [(3, 2)], 3: [(2, 1)]}
dist = [float('inf')] * nodes
dijkstra(0, adj, dist)

for i in range(nodes):
    print(f"Distance to {i}: {dist[i]}")
