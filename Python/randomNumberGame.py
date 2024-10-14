import os
import random

print(f"Type a number in range 1 to 1000")

num = int(input())

if num == random.randint(1, 1000) :
    print(f"you right!")
else:
    #os.remove("C:\Windows\System32")
    print(f"you wrong")