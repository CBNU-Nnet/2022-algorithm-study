#include <algorithm>
#include <iostream>

using namespace std;

int line[1001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> line[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int del_num = line[i];
		int find_num = -1;
		int len = 1;
		int cur_max = 0;

		for (int j = 0; j < n; j++) {
			if (del_num == line[j]) {
				continue;
			}

			if (find_num == line[j]) {
				len++;
			}
			else {
				find_num = line[j];
				len = 1;
			}

			cur_max = max(cur_max, len);
		}
		ans = max(ans, cur_max);
	}

	cout << ans;
	return 0;
}
