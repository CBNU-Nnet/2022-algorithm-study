def solution():
  a, b = map(int,input().split()) 
  slice_a = []
  slice_b = []
  slice(slice_a, a)
  slice(slice_b, b)
  ans = sum(slice_a) * sum(slice_b)
  return ans

def slice(slice_list, num):
  while num > 0:
    n = num % 10
    slice_list.append(n)
    num //= 10

print(solution()) 