#include <iostream>
#include <string>

using namespace std;

char tolower(char alpha) {
	if ('A' <= alpha && alpha <= 'Z')
		return (alpha - 'A') + 'a';

	return alpha;
}

bool assign_shortcut (bool* is_assign_alph, char alpha) {
	int lower_alpha_idx = tolower(alpha) - 'a';

	if (!is_assign_alph[lower_alpha_idx]) {
		return true;
	}

	return false;
}

void print_option(string& option, bool* is_assign_alph, int idx) {
	int lower_alpha_idx = tolower(option[idx]) -'a';
	is_assign_alph[lower_alpha_idx] = true;

	for (int i = 0; i < option.length(); i++) {
		if (i == idx) {
			cout << '[' << option[i] << "]";
		}
		else {
			cout << option[i];
		}
	}

	cout << "\n";
}

int main() {
	int N;
	cin >> N;
	cin.ignore();

	bool is_assign_alph[26] = { 0, };

	while (N--) {
		string option;
		getline(cin, option);

		int word_first_idx = -1;
		int word_mid_idx = -1;

		bool start_word = true;
		for (int idx = 0; idx < option.length(); idx++) {
			if (option[idx] != ' ' && assign_shortcut(is_assign_alph, option[idx])) {
				if (start_word && word_first_idx == -1) {
					word_first_idx = idx;
					break;
				}
				else if (!start_word && word_mid_idx == -1) {
					word_mid_idx = idx;
				}
			}

			if (option[idx] == ' ') {
				start_word = true;
			}
			else {
				start_word = false;
			}
		}

		if (word_first_idx != -1) {
			print_option(option, is_assign_alph, word_first_idx);
		}
		else if (word_mid_idx != -1) {
			print_option(option, is_assign_alph, word_mid_idx);
		}
		else {
			cout << option << "\n";
		}
	}

	return 0;
}
