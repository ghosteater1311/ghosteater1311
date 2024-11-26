def dfs(node, adj, visited):
    visited[node] = True
    print(node, end=" ")

    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor, adj, visited)

# Example
nodes = 5
adj = [[1, 2], [0, 3], [0, 4], [1], [2]]
visited = [False] * nodes
dfs(0, adj, visited)
