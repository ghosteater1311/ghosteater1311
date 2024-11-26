from queue import Queue

# Create a queue
queue = Queue()

# Enqueue
queue.put("A")
queue.put("B")
queue.put("C")

# Dequeue
while not queue.empty():
    print(queue.get())  # Removes and returns the front element
