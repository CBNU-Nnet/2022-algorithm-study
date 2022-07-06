#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tree[10000];
void Postfix(int start, int end)
{
	if (start == end)
		cout << tree[start] << '\n';
	for (int i = start + 1; i <= end; i++)
	{
		if (tree[start] < tree[i]) // if a right sub tree exists
		{
			Postfix(start + 1, i - 1); // left sub tree
			Postfix(i, end); // right sub tree
			cout << tree[start] << '\n'; // root node
			break;
		}
		if (i == end) // if no right sub tree
		{
			Postfix(start + 1, end);
			cout << tree[start] << '\n';
		}
	}
	
}
int main()
{
	int n, cnt = 0;
	while (cin >> n)
	{
		tree[cnt++] = n;
	}
	Postfix(0, cnt - 1);
	return 0;
}