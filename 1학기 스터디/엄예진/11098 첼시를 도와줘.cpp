#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, p;
	cin >> n;//n�迭�� ���ڿ� �Է�
	while (n--)
	{
		cin >> p;//p�迭�� ���ڿ� �Է�
		vector<pair<int, string>>s(p);
		int i = 0;
		int max = 0;
		int res;
		while (p--)
		{
			cin >> s[i].first >> s[i].second;
			if (s[i].first > max) {
				max = s[i].first;
				res = i;

			}
			i++;
		}
		cout << s[res].second << endl;
	}
}