# 4-node weighted graph weight matrix
n = 4
weight_matrix = [[float('inf')] * n for _ in range(n)]

# Add weights
weight_matrix[0][1] = 5  # Weight from node 0 to node 1
weight_matrix[1][2] = 2  # Weight from node 1 to node 2

# Set diagonal to 0 (no cost to self)
for i in range(n):
    weight_matrix[i][i] = 0

# Display
for row in weight_matrix:
    print(row)
