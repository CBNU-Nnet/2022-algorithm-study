def solution(record):
  answer = []
  uid_arch = {} # 유저아이디 : 닉네임 을 저장하는 딕셔너리

  # 반복문을 돌며 기록 처리
  for rec in record:
    rec_splited = rec.split()
    if (rec_splited[0] == 'Enter') or (rec_splited[0] =='Change'):
      uid_arch[rec_splited[1]] = rec_splited[2]

  # 반복문을 돌며 처리된 기록을 바탕으로 메시지 저장
  for rec in record:
    rec_splited = rec.split()
    if rec_splited[0] == 'Enter':
      answer.append(f"{uid_arch[rec_splited[1]]}님이 들어왔습니다.")
    elif rec_splited[0] == 'Leave':
      answer.append(f"{uid_arch[rec_splited[1]]}님이 나갔습니다.")
      
  return answer