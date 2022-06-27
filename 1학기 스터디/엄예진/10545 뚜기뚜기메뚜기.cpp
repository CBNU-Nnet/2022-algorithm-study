#include <iostream>
#include <string>
using namespace std;

int alphabet[26] = { 2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999 };
int number[10];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 10; i++)
	{
		int temp;
		cin >> temp;
		number[temp] = i;

	}
	string s;
	cin >> s;
	int prev = -1;
	for (int i = 0; i < s.length(); i++)
	{
		int temp = alphabet[s[i] - 'a'];
		if (prev == temp % 10)
			cout << "#";
		while (temp) {
			cout << number[temp % 10];
			prev = temp % 10;
			temp /= 10;
		}
	}

cout << "\n";
return 0;
}