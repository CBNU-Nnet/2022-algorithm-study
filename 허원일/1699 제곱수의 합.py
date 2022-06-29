N = int(input())
d = [0 for i in range(N+1)]
square = [i*i for i in range(1, 317)]

for i in range(1, N+1):
  s = []
  for j in square:
    if j > i:
      break  
    s.append(d[i-j])
  d[i] = min(s) + 1

print(d[N])