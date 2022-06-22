#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string find_shortkey(bool* repeat_alpha, string option_word, int loc) {
	bool find_shortkey = false; // 단축키를 지정이 가능한가?
	char lower_letter = tolower(option_word[loc]);  // 소문자로 변환

	if (!repeat_alpha[lower_letter - 'a']) { // 소문자를 index로 바꾼 후, 중복 체크
		find_shortkey = true; // 단축키 지정이 가능함.
		option_word = option_word.substr(0, loc) + "[" + option_word[loc] + "]" + option_word.substr(loc + 1); // 단축키에 [ ] 붙히기
		repeat_alpha[lower_letter - 'a'] = true; // 중복처리
	}

	if (find_shortkey) { // 단축키 지정이 가능하다면
		return option_word;  // [ ] 를 붙힌 문자열 반환
	}
	else {
		return "";
	}
}
int main() {
	int n;
	cin >> n;

	cin.ignore(); // 버퍼 비우기

	bool repeat_alpha[26] = { 0, }; // 알파벳 중복처리

	for (int i = 0; i < n; i++) {
		string input_option; 
		getline(cin, input_option); // 옵션 입력받기

		istringstream iss(input_option); // 문자열 추출을 위한 입력스트림
		string str_buffer; // 문자열 추출을 위한 버퍼

		vector<string> option_words; // 추출된 문자열을 저장하는 vector
		while (getline(iss, str_buffer, ' ')) { // python의 split 함수와 동일
			option_words.push_back(str_buffer); // split 한 결과를 vector에 담음 
		}

		// 각 첫번째 글자 확인
		string ret; // 단축키를 지정한 문자열을 리턴 받는 변수
		for (string& option_word : option_words) {
			ret = find_shortkey(repeat_alpha, option_word, 0); // 각 단어의 첫번째 글자가 단축키로 지정이 가능한가?

			if (ret != "") {
				option_word = ret;
				break;
			}
		}

		if (ret == "") {
			for (string &option_word : option_words) {
				for (int i = 0; i < option_word.length(); i++) {
					ret = find_shortkey(repeat_alpha, option_word, i); // 왼쪽부터 차례대로 단축키 지정이 가능한가?

					if (ret != "") {
						option_word = ret;
						break;
					}
				}

				if (ret != "") {
					break;
				}
			}
		}

		for (auto option_word : option_words) {
			cout << option_word << " ";
		}
		cout << "\n";
	}

	return 0;
}
