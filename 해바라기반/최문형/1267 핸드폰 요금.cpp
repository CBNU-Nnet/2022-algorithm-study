#include <iostream>

using namespace std;

// N = 20, 모든 통화시간 = 10,000
// 영식 = 20 * ((10,000 / 30) * 10) = no overflow
// 민식 = 20 * ((10,000 / 60) * 15) = no overflow
int main() {
	int N;
	cin >> N;

	int Y = 0, M = 0;

	while (N--) {
		int call_time;
		cin >> call_time;

		Y += ((call_time / 30) + 1) * 10;
		M += ((call_time / 60) + 1) * 15;
	}

	if (Y < M) {
		cout << "Y " << Y;
	}
	else if (Y > M) {
		cout << "M " << M;
	}
	else {
		cout << "Y M " << M;
	}

	return 0;
}
