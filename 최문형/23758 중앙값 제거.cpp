#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<int> arr(n);
	for (auto& i : arr) {
		cin >> i;
	}

	sort(arr.begin(), arr.end(), greater<int>()); // 오름차순으로 정렬

	long long cnt = 0;
	for (int i = n / 2; i < n; i++) { // 중앙부터 그 뒤의 값들에 대해 반복함.
		if (arr[i] < 1) { // arr[i]가 1 인 경우, 2로 나누면 0이 나오므로 반복문에서 탈출함.
			break;
		}

		while (arr[i] != 1) { 
			arr[i] /= 2;  // arr[i]가 1이 될 때까지 2로 나눔
			cnt++;        // 나눈 횟수 계산
		}
	}

	cout << cnt + 1; // arr[i] 가 1일 때 탈출하므로 결과값에는 1을 따로 더해줘야 함.

	return 0;
}
