n = int(input())
for i in range(n):
    p = int(input())
    max = 0
    whoAreMax = ""
    for j in range(p):
        price, name = input().split()
        if int(price) > max:
            max = int(price)
            whoAreMax = name
            
    print(whoAreMax)