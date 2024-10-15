import os
import random
import time

print(f"Type a number in range 1 to 1000")

num = int(input())

if num == random.randint(1, 1000) :
    print(f"Lucky Dog!")
else:
    #os.remove("C:\Windows\System32")
    time.sleep(30)
    print(f"Noob")