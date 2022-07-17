#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

long long** MulMatrix(int n, long long** mLeft, long long** mRight)
{
	long long** mTemp = (long long**)malloc(sizeof(long long*) * n);
	for (int i = 0; i < n; i++)
	{
		mTemp[i] = (long long*)calloc(n, sizeof(long long));
	}
	for (int left = 0; left < n; left++)
	{
		long long col = 0;
		for (int right = 0; right < n; right++)
		{
			for (int index = 0; index < n; index++)
			{
				mTemp[left][right] = mTemp[left][right] + mLeft[left][index] * mRight[index][right];
				mTemp[left][right] %= 1000;
			}

		}
	}
	return mTemp;
}
int main()
{
	int n, b;
	long long** a,  **a_result;
	cin >> n >> b;
	a = (long long**)malloc(sizeof(long long*) * n);
	a_result = (long long**)malloc(sizeof(long long*) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long*)malloc(sizeof(long long) * n);
		a_result[i] = (long long*)calloc(n, sizeof(long long)); // 단위행렬
	}
	bitset<100>bs(b);
	string bBinary = bs.to_string();
	bBinary = bBinary.substr(bBinary.find('1'));
	for (int i = 0; i < n; i++) // 입력
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		a_result[i][i] = 1;
	}

	vector<long long**> a_mul;
	a_mul.push_back(a);
	for (int i = 0; i < bBinary.length() - 1; i++)
	{
		a_mul.push_back(MulMatrix(n, a_mul[i], a_mul[i])); // A^2, A^4, A^8, ...
	}
	for (int i = 0; i < bBinary.length(); i++) // 행렬 곱셈
	{
		if (bBinary[i] == '1')
		{
			a_result = MulMatrix(n, a_mul[a_mul.size() - 1 - i], a_result);
		}
	}

	for (int i = 0; i < n; i++) // 출력
	{
		for (int j = 0; j < n; j++)
		{
			cout << a_result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}