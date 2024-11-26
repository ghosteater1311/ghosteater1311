# Directed graph adjacency list
graph = {
    "A": ["B", "C"],
    "B": ["D"],
    "C": [],
    "D": ["C"]
}

# Access neighbors
print(graph["A"])  # Output: ['B', 'C']
