n = int(input())
for _ in range(n):
  N, M = map(int, input().split())
  if N < 12 or M < 4: # L4 자리가 존재할 수 없는 경우
    print(-1)
  else:
    print(M*11 + 4)