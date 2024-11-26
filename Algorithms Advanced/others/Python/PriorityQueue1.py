from queue import PriorityQueue

# Create a priority queue
pq = PriorityQueue()

# Insert elements (priority, element)
pq.put((3, "Task A"))
pq.put((1, "Task B"))
pq.put((2, "Task C"))

# Remove elements based on priority
while not pq.empty():
    priority, task = pq.get()
    print(f"Processing {task} with priority {priority}")
