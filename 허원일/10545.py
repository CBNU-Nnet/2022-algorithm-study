keypad = {"1":"", "2":"abc", "3":"def", 
          "4":"ghi", "5":"jkl", "6":"mno", 
          "7":"pqrs", "8":"tuv", "9":"wxyz"} # 고장나기 전 키패드 상태가 저장된 딕셔너리
new_num = input().split() # 9개 정수 입력
new_keypad = {} # 고장난 후의 키패드 상태를 저장할 딕셔너리
for i in range(len(new_num)) : # 입력받은 숫자에 해당하는 value를 새로운 키패드의 원래의 key의 value로 대입
    new_keypad[str(i+1)]= keypad[new_num[i]]
msg = input() # 메시지 입력

result = ""
key_buffer = []
for i in range(len(msg)) :
    for key, value in new_keypad.items() :
        if msg[i] in value : # value에 메시지의 문자열 내 문자가 포함되는 경우
            if (len(key_buffer) > 0) and (key_buffer[-1] == key) : # 마지막 입력 숫자가 현재의 입력 숫자와 같은 경우
                result = result + "#" + (value.find(msg[i])+1) * key # find->인덱스리턴
            else :
                result += (value.find(msg[i])+1) * key
            key_buffer.append(key) # 현재의 입력 숫자 리스트에 저장
print(result)
