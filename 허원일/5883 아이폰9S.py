N = int(input())
line = [] # 줄 정보
long_seq = []

# 최대길이를 계산하는 함수
def max_seq_cap(line):
  max_count = 1
  count = 1
  for i in range(0, len(line)-1):
    if line[i] == line[i+1]: # 연속된 두 원소가 같으면 count 증가
      count += 1
    else: # 다르면 max_count 초기화
      max_count = max(count, max_count)
      count = 1 # count 초기화
  return max(count, max_count) # 예외처리 - new_line이 한 용량으로만 이루어진 경우

for _ in range(N):
  cap = int(input())
  line.append(cap)
set = set(line) # 줄에 있는 구매자들이 원하는 용량종류를 담는 집합

for element in set:
  new_line = line.copy() # line을 복사해 new_line을 생성
  while element in new_line: # 특정 용량을 원하는 사람을 모두 뺌
    new_line.remove(element)
  long_seq.append(max_seq_cap(new_line))

print(max(long_seq))