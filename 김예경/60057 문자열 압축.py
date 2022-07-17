def solution(s):
    res=list()  # 문자열 길이를 저장할 list

    # 문자열 길이가 1일 때 처리
    if len(s)==1:
        return 1

    for j in range(1, len(s)//2+1): #j는 slice 단위
        cnt=1
        ss=""
        temp=""
        for i in range(0,len(s)+1,j):
            if s[i:i+j]==temp:
                cnt+=1
            else:
                if cnt==1:
                    ss+=temp
                else:
                    ss+=str(cnt)+temp 
                    cnt=1
                temp=s[i:i+j] 

        # 뒤쪽 문자열 처리    
        if cnt==1:
            ss+=temp
        else:
            ss+=str(cnt)+temp
        res.append(len(ss)) 

    # 가장 짧은 것의 길이 return
    return min(res)
 

print(solution("aabbaccc"))
print(solution("ababcdcdababcdcd"))
print(solution("abcabcdede"))
print(solution("abcabcabcabcdededededede"))
print(solution("xababcdcdababcdcd"))
