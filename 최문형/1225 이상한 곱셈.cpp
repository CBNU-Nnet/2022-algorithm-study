#include <iostream>

using namespace std;

int multiply(char a, char b) {
	return (a - '0') * (b - '0');
}

int main() {
	string a, b;
	cin >> a >> b;

	long long ans = 0;
	for (auto i : a) {
		for (auto j : b) {
			ans += multiply(i, j);
		}
	}

	cout << ans;

	return 0;
}
