# 4-node graph adjacency matrix
n = 4
adj_matrix = [[0] * n for _ in range(n)]

# Add edges
adj_matrix[0][1] = 1  # Edge from node 0 to node 1
adj_matrix[1][2] = 1  # Edge from node 1 to node 2

# Display
for row in adj_matrix:
    print(row)
