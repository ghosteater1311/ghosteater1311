from collections import deque

# Create a queue
queue = deque()

# Enqueue (add elements to the back)
queue.append("A")
queue.append("B")
queue.append("C")

# Dequeue (remove elements from the front)
while queue:
    print(queue.popleft())  # Removes and returns the leftmost element
