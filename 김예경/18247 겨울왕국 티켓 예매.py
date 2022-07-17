t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    if m<4 or n<12: # L=12행
        print(-1)
    else:
        print(11*m+4)