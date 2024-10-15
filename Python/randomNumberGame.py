import os
import random
import time

print(f"Type a number in range 1 to 100")

num = int(input())

randnum = random.randint(1, 100)

tm = randnum

if num == randnum:
    print(f"Lucky Dog!")
else:
    #os.remove("C:\Windows\System32")
    print(f"You have {tm} seconds")
    while randnum > 0:
        time.sleep(1)
        print(f"{randnum}")
        randnum -= 1
    print(f"Noob")