n = int(input())
sum = 0

for i in range(1, n + 1):
    sum += 1/i
print(f"{sum:0.5f}")