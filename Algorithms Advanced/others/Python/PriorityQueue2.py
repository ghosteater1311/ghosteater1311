import heapq

# Create an empty priority queue
pq = []

# Insert elements with priority (priority, element)
heapq.heappush(pq, (3, "Task A"))  # Priority 3
heapq.heappush(pq, (1, "Task B"))  # Priority 1 (highest priority)
heapq.heappush(pq, (2, "Task C"))  # Priority 2

# Remove elements based on priority
while pq:
    priority, task = heapq.heappop(pq)
    print(f"Processing {task} with priority {priority}")
