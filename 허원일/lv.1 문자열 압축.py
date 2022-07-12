def solution(s):
    result = len(s) # result를 s의 길이으로 초기화 (이후 min 함수를 통해 최솟값으로 갱신 위해)
    for slice_len in range(1, len(s)+1):
      compressed = "" # 압축된 문자열을 담을 compressed
      count = 1 # 압축된 횟수를 나타내는 count
      prev = s[0:slice_len]
      for start in range(slice_len, len(s), slice_len):
        cur = s[start:start+slice_len]
        if prev == cur: # 이전 문자열과 같으면 압축된 횟수 증가
          count += 1 
        else: # 다르면 compressed에 바로 붙임
          compressed += str(count) + prev if count >= 2 else prev
          prev = cur # prev를 cur로 초기화
          count = 1 # count 초기화
      compressed += str(count) + prev if count >= 2 else prev # 마지막 문자열 처리

      result = min(result, len(compressed)) # 기존의 result값과 현재 압축된 문자열의 길이를 비교하여 result값 갱신
    return result 