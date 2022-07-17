#include <string>
#include <vector>
#include <cmath>

using namespace std;

// N의 자릿수를 구하는 함수입니다.
int digit(int N) {
    if (N == 1) {
	return 0; // 0은 생략가능함.
    }
    
    
    int N_digit = 0;
    
    while (N) {
	N_digit++;
	N /= 10; // 10씩 나눠가면서 자릿수 계산하기
    }
    
    return N_digit;
}

int solution(string s) {
    int answer = s.size();
    
    // 압축할 문자열의 크기는 1 ~ s.size() / 2 까지
    for (int cut_size = 1; cut_size <= s.size() / 2; cut_size++) {
	string pre_str = s.substr(0, cut_size); // 0 ~ cut_size 만큼 자르기
	int same_cnt = 1, tot_size = 0;
	
	bool is_finish_same = false; // 마지막에 압축된 문자열을 봤을 떄, 성공했다면 tot_size 값을 더하지 못함
	int find_time = ceil(double(s.size() / cut_size)); // 반복 횟수는 '문자열의 길이'를 cut_size 를 나눈 천장함수 값
	int i = cut_size;
	while (find_time--) {
	    if (i + cut_size > s.size()) { // 마지막 문자열을 cut_size 만큼 자르지 못했다면, 
		tot_size += s.size() - i;  // tot_size에 자르지 못한 크기만큼 더해줌
	    }
	
	    if (pre_str != s.substr(i, cut_size)) { // 압축하려는 문자열이 이전에 문자열이랑 다르다면 => 압축실패
		tot_size += cut_size + digit(same_cnt); // cut_size + (same_cnt)의 크기 만큼 tot_size에 더해줌
		pre_str = s.substr(i, cut_size); // '이전' 문자열에 현재 자른 문자열을 더해줌
		
		same_cnt = 1;
		is_finish_same = false; // 반복문을 종료했을 떄, 마지막으로 압축하려는 문자열은 이전 문자열과 달랐다는 것을 의미
	    }
	    else {
		is_finish_same = true; // 반복문을 종료했을 때, 마지막으로 압축하려는 문자열은 이전 문자열과 같았다는 것을 의미
		same_cnt++;
	    }
	
	    i += cut_size;
	}
	
	if (is_finish_same == true) {
	    tot_size += cut_size + digit(same_cnt);
	}
    
	answer = min(answer, tot_size); // 제일 많이 압축한 문장을 출력하는 것이 목적
    }
    return answer;
}
