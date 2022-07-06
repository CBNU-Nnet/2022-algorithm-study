#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = i;

		for (int j = sqrt(i); j > 0; j--) {
			dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
		}
	}

	cout << dp[n];

	return 0;
}
