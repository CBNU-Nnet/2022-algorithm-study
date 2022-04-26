n = int(input())
input_list = list(map(int, input().split()))

def ys(n):
    return (n//30+1)*10
def ms(n):
    return (n//60+1)*15

ys_sum = 0
ms_sum = 0

for i in range(n):
    ys_sum += ys(input_list[i])
    ms_sum += ms(input_list[i])
    
if ys_sum>ms_sum:
    print(f"M {ms_sum}")
elif ys_sum<ms_sum:
    print(f"Y {ys_sum}")
else:
    print(f"Y M {ys_sum}")
