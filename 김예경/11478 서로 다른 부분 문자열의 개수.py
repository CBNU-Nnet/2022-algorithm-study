str = input()
arr = []
#문자열을 list에 추가
for i in range(len(str)):
    for j in range(len(str)-i):
        arr.append(str[j:j+1+i])   
#중복 제거
arr = set(arr)
arr = list(arr)
#출력
print(len(arr))