# 영식 Y, 민식 M
n = int(input())
li = list(map(int, input().split()))
Y = M = 0

for i in li:
    Y += (i // 30 + 1) * 10
    M += (i // 60 + 1) * 15

if Y > M:
    print('M', M)
elif Y == M:
    print('Y', 'M', Y)
else:
    print('Y', Y)