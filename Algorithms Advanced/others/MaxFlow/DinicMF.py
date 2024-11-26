from collections import deque

class Dinic:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n)]
    
    def add_edge(self, u, v, capacity):
        self.adj[u].append([v, len(self.adj[v]), capacity])
        self.adj[v].append([u, len(self.adj[u]) - 1, 0]) # reverse edge
    
    def bfs(self, s, t):
        self.level = [-1] * self.n
        self.level[s] = 0
        queue = deque([s])
        
        while queue:
            node = queue.popleft()
            for v, _, capacity in self.adj[node]:
                if capacity > 0 and self.level[v] == -1:
                    self.level[v] = self.level[node] + 1
                    queue.append(v)
        
        return self.level[t] != -1
    
    def dfs(self, node, flow, t, ptr):
        if node == t:
            return flow
        
        while ptr[node] < len(self.adj[node]):
            v, rev, capacity = self.adj[node][ptr[node]]
            if self.level[v] == self.level[node] + 1 and capacity > 0:
                pushed = self.dfs(v, min(flow, capacity), t, ptr)
                if pushed > 0:
                    self.adj[node][ptr[node]][2] -= pushed
                    self.adj[v][rev][2] += pushed
                    return pushed
            ptr[node] += 1
        
        return 0
    
    def max_flow(self, s, t):
        flow = 0
        while self.bfs(s, t):
            ptr = [0] * self.n
            while True:
                pushed = self.dfs(s, float('inf'), t, ptr)
                if pushed == 0:
                    break
                flow += pushed
        return flow

# Example usage
n, m = map(int, input().split())  # Number of nodes and edges
dinic = Dinic(n)
for _ in range(m):
    u, v, cap = map(int, input().split())
    dinic.add_edge(u, v, cap)

s, t = map(int, input().split())  # Source and sink
print(dinic.max_flow(s, t))
