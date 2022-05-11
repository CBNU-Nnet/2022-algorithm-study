#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

vector<bool> eratos; // 소수만 false
vector<int> ans_list;
vector<bool> ans_visited;
vector<int> cows;
int n, m;

// 에라토스테네스의 채
void era_init() {
	eratos[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (eratos[i]) {
			continue;
		}

		for (int j = 2 * i; j < MAX; j += i) {
			eratos[j] = true;
		}
	}
}

// n과 m 문제처럼 백트래킹을 사용해야 함.
void n_and_m(int depth, int start_idx, int sum) {
	if (depth == m) {
		// 정답으로 등록되지 않은 소수만 정답 배열에 추가함.
		if (!eratos[sum] && !ans_visited[sum]) {
			ans_visited[sum] = true; // 중복 설정
			ans_list.push_back(sum); // 나중에 sort를 위해 정답 배열에 넣어둠
		}

		return;
	}

	for (int i = start_idx; i < n; i++) {
		n_and_m(depth + 1, i + 1, sum + cows[i]);
	}
}

int main() {
	cin >> n >> m;

	cows.assign(n, 0);
	for (auto& cow : cows) {
		cin >> cow;
	}

	eratos.assign(MAX, false);
	ans_visited.assign(MAX, false);
	era_init(); // 에라토스태네스의 채 실행

	n_and_m(0, 0, 0);


	// 정답 배열에 아무것도 들어있지 않다면, 소수가 존재하지 않는다는 뜻 ==> -1 출력
	if (ans_list.size() == 0) {
		cout << -1;
	}
	else {
		// 정답 배열은 오른차순으로 출력되어야 하므로 sorting을 따로 해줘야 함.
		sort(ans_list.begin(), ans_list.end());
		for (auto i : ans_list) {
			cout << i << " ";
		}
	}

	return 0;
}
