#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int calc(int a, int b, int oper) {
	if (oper == '+') {
		return a + b;
	}
	else if (oper == '-') {
		return a - b;
	}
	else if (oper == '*') {
		return a * b;
	}
	else {
		return a / b;
	}
}

int main() {
	int a, b, c;
	char oper_one, oper_two;

	cin >> a >> oper_one >> b >> oper_two >> c;
	int ans_one, ans_two;

	ans_one = calc(calc(a, b, oper_one), c, oper_two);
	ans_two = calc(a, calc(b, c, oper_two), oper_one);

	cout << min(ans_one, ans_two) << "\n";
	cout << max(ans_one, ans_two);

	return 0;
}
