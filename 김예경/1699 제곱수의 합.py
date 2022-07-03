n = int(input())
 
dp = [i for i in range (n+1)]
print(dp)
for i in range(1, n+1):
    for j in range(1, i):
        if (j * j) > i:
            break
        if dp[i] > dp[i - j * j] + 1:   #  dp[i] = min(dp[i], dp[i - j * j] + 1) 시간초과
            dp[i] = dp[i - j * j] + 1
 
print(dp[n])