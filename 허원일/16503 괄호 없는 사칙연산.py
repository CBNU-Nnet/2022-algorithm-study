a, o_1, b, o_2, c = input().split()
k_1 = int(a)
k_2 = int(b)
k_3 = int(c)

def two_op_cal(op1, oper, op2):
  if oper == "+":
    return op1 + op2
  elif oper == "-":
    return op1 - op2
  elif oper == "*":
    return op1 * op2
  elif oper == "/":
    return int(op1 / op2)
result1 = two_op_cal(two_op_cal(k_1, o_1, k_2), o_2, k_3)
result2 = two_op_cal(k_1, o_1, two_op_cal(k_2, o_2, k_3))

if (result1 < result2):
                print(result1)
                print(result2)   
else:
  print(result2)
  print(result1)