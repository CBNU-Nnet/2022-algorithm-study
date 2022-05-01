#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int player_cnt;
		cin >> player_cnt;

		string ans;
		int max_value = 0;
		for (int i = 0; i < player_cnt; i++) {
			int cur_value;
			string cur_name;

			cin >> cur_value >> cur_name;  // 선수의 가격과 이름을 입력받음

			if (max_value < cur_value) {   // (구단 내)에서 제일 비싼 선수 등장
				max_value = cur_value; // max_value를 최대값으로 갱신함.
				ans = cur_name;        // ans 에는 제일 비싼 선수의 이름으로 갱신
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
