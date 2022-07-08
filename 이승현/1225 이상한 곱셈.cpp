#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	unsigned long long sum = 0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			sum = sum + (a[i] - '0') * (b[j] - '0');
		}
	}
	cout << sum;
	return 0;
}