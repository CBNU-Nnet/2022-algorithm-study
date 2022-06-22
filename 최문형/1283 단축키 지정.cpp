#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	int n;
	cin >> n;

	cin.ignore();

	bool repeat_letter[26] = { 0, };
	while (n--) {
		string input_option;
		getline(cin, input_option);

		// 단어의 첫 글짜를 단축키로 지정
		bool word_first_flag = true; // 단어의 첫 글자인가?
		bool find_shortkey = false;  // 단축키로 지정한 글자를 찾았는가?
		for (int i = 0; i < input_option.length(); i++) {
			if (word_first_flag) {
				word_first_flag = false;

				char lower_letter = tolower(input_option[i]) - 'a'; // 소문자 변환

				if (!repeat_letter[lower_letter]) { // 단축키로 지정할 글자를 찾음
					repeat_letter[lower_letter] = true; // 중복처리
					cout << input_option.substr(0, i) << '[' << input_option[i] << ']' << input_option.substr(i + 1) << "\n"; // 해당 옵션에 대해 단축키를 찾았으므로 정답 출력
					find_shortkey = true;
					break;
				}
			}
			
			else if (input_option[i] == ' ') { // 단어의 첫 글자는 공백뒤에 주어짐
				word_first_flag = true; // 단어의 첫 글자를 찾았으므로 true로 함
			}
		}

		if (!find_shortkey) { // 단축키로 지정 할 글자를 찾지 못했다면
			for (int i = 0; i < input_option.length(); i++) {
				if (input_option[i] == ' ') { // 공백은 건너뜀
					continue;
				}

				char lower_letter = tolower(input_option[i]) - 'a'; // 소문자 변환

				if (!repeat_letter[lower_letter]) { // 해당 글자(소문자)가 이미 단축키로 되어있는지 확인
					repeat_letter[lower_letter] = true; // 중복처리
					cout << input_option.substr(0, i) << '[' << input_option[i] << ']' << input_option.substr(i + 1) << "\n"; // 출력
					find_shortkey = true; 
					break;
				}
			}
		}

		if (!find_shortkey) { // 결국 단축키로 지정할 글자를 찾지 못했다면,
			cout << input_option << "\n"; // 입력으로 들어온 문자열을 그대로 출력
		}
	}

	return 0;
}
