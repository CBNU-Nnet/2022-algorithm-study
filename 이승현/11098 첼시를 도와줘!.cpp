#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vector<int> prices;
		vector<string> names;
		for (int j = 0; j < p; j++)
		{
			int price;
			string name;
			cin >> price >> name;
			prices.push_back(price);
			names.push_back(name);
		}
		int max_index = max_element(prices.begin(), prices.end()) - prices.begin(); // max_element: �ִ밪�� ����Ű�� �ݺ��� ��ȯ => *max_element���� �ִ밪 ���ϱ�
		cout << names[max_index] << endl;
	}
	return 0;
}