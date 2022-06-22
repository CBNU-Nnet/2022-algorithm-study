n = int(input())
for _ in range(n):
    player_num = int(input())
    player_list = {}  
    for _ in range(player_num):
        price, name = input().split()
          price = int(price)
          player_list[price] = name
    print(player_list.get(max(player_list.keys())))
 