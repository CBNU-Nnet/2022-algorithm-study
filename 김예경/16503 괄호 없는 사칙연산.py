#입력받기
k1, o1, k2, o2, k3 = input().split()
k1, k2, k3 = int(k1), int(k2), int(k3)

#수를 입력해 계산
def calculate(a, op, b):
    if op == '+':
        ans = a + b
    elif op == '-':
        ans = a - b
    elif op == '*':
        ans = a * b
    elif op == '/':
        ans = a // b
        if a<0 or b<0:
            ans = ans+1
    return ans

# 앞부터 연산
temp = calculate(k1, o1, k2)
ans1 = calculate(temp, o2, k3)
# 뒤부터 연산
temp = calculate(k2, o2, k3)
ans2 = calculate(k1, o1, temp)

# 출력하기
if ans1 < ans2:
    print(ans1)
    print(ans2)
else:
    print(ans2)
    print(ans1)