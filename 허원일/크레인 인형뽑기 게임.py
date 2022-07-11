basket = []
result = 0

def solution(board, moves):
  for i in moves:
    for j in range(len(board)):
      if board[len(board)-1][i-1] == 0:
        break
      item = board[j][i-1]
      if item != 0:
        board[j][i-1] = 0
        stack_cmp(basket, item)
        break
  return result
  
def stack_cmp(list, data):
  if len(list) == 0 or list[-1] != data: 
    basket.append(data)
    return
  if list[-1] == data:
    del list[-1]
    global result
    result += 2
    return