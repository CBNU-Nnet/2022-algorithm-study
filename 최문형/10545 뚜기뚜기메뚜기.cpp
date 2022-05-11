#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Keypad {
	int num;
	int location;
};

int main() {
	map<char, Keypad> keypad;
	keypad['a'] = { 2, 0 };
	keypad['b'] = { 2, 1 };
	keypad['c'] = { 2, 2 };

	keypad['d'] = { 3, 0 };
	keypad['e'] = { 3, 1 };
	keypad['f'] = { 3, 2 };

	keypad['g'] = { 4, 0 };
	keypad['h'] = { 4, 1 };
	keypad['i'] = { 4, 2 };

	keypad['j'] = { 5, 0 };
	keypad['k'] = { 5, 1 };
	keypad['l'] = { 5, 2 };

	keypad['m'] = { 6, 0 };
	keypad['n'] = { 6, 1 };
	keypad['o'] = { 6, 2 };

	keypad['p'] = { 7, 0 };
	keypad['q'] = { 7, 1 };
	keypad['r'] = { 7, 2 };
	keypad['s'] = { 7, 3 };

	keypad['t'] = { 8, 0 };
	keypad['u'] = { 8, 1 };
	keypad['v'] = { 8, 2 };

	keypad['w'] = { 9, 0 };
	keypad['x'] = { 9, 1 };
	keypad['y'] = { 9, 2 };
	keypad['z'] = { 9, 3 };
	
	vector<int> to_broken_idx(10);
	for (int i = 1; i < 10; i++) {
		int temp;
		cin >> temp;

		to_broken_idx[temp] = i;
	}

	string str;
	cin >> str;

	int pre = 0;
	for (auto i : str) {
		Keypad cur = keypad[i];

		if (cur.num == pre) {
			cout << "#";
		}

		for (int j = 0; j <= cur.location; j++) {
			cout << to_broken_idx[cur.num];
		}

		pre = cur.num;
	}
	

	return 0;
}
