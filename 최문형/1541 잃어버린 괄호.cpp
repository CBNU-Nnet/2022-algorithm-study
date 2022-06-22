#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string input;
	cin >> input;

	int curNum = 0, totalSum = 0;
	deque<int> dq;
	int i = 0;

	while (i < input.size()) {
		if (input[i] >= '0' && input[i] <= '9') {
			curNum = 0;

			while (input[i] >= '0' && input[i] <= '9') {
				curNum *= 10;
				curNum += input[i] - '0';

				i++;
			}
		}	

		if (i < input.length() && input[i] == '+') {
			totalSum += curNum;
		}

		else {
			dq.push_back(totalSum + curNum);
			totalSum = 0;
		}

		i++;
	}

	int ret = dq[0];
	for (int i = 1; i < dq.size(); i++) {
		ret -= dq[i];
	}

	cout << ret;

	return 0;
}
