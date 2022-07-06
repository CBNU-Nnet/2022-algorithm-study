#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string S;
	cin >> S;

	set<string> difference;
	string sub_str;
	for (int i = 0; i < S.length(); i++) {
		sub_str = "";

		for (int j = i; j < S.length(); j++) {
			sub_str += S[j];
			difference.insert(sub_str);
		}
	}

	cout << difference.size();

	return 0;
}