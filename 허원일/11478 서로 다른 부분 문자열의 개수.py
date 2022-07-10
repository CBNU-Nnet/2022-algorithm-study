string = input()
set = set() # 부분 문자열을 담을 세트 자료형 선언
for slice_len in range(1, len(string)+1): # 이중 for 중 첫번째 for - 부분문자열의 길이 기준
  for j in range(0, len(string)): # 두번째 for - 부분문자열의 시작 인덱스 기준
    set.add(string[j:j+slice_len]) # 세트 자료형에 해당 문자열 추가 (세트에 없으면)

print(len(set)) 