def floyd_warshall(graph, nodes):
    dist = [[graph[i][j] for j in range(nodes)] for i in range(nodes)]

    for k in range(nodes):
        for i in range(nodes):
            for j in range(nodes):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for row in dist:
        print(" ".join(["INF" if x == float('inf') else str(x) for x in row]))

# Example
nodes = 4
graph = [
    [0, 3, float('inf'), 5],
    [2, 0, float('inf'), 4],
    [float('inf'), 1, 0, float('inf')],
    [float('inf'), float('inf'), 2, 0]
]
floyd_warshall(graph, nodes)
