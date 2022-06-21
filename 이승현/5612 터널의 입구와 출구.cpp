#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int in, out;
	cin >> n >> m;
	int max = m, cnt = m;
	for (int i = 0; i < n; i++)
	{
		cin >> in >> out;
		cnt += in - out;
		if (cnt < 0)
		{
			max = 0;
			break;
		}
		if (cnt > max)
			max = cnt;
	}
	cout << max;
	return 0;
}