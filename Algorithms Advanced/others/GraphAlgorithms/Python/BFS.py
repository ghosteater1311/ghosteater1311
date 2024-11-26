from collections import deque

def bfs(start, adj, visited):
    queue = deque([start])
    visited[start] = True

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

# Example
nodes = 5
adj = [[1, 2], [0, 3], [0, 4], [1], [2]]
visited = [False] * nodes
bfs(0, adj, visited)
