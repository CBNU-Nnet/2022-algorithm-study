#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> sixPrice;
	vector<int> onePrice;
	int totalPrice = 0;
	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		sixPrice.push_back(a);
		onePrice.push_back(b);
	}
	int onePriceMin = *min_element(onePrice.begin(), onePrice.end());
	int sixPriceMin = *min_element(sixPrice.begin(), sixPrice.end());
	if (onePriceMin * 6 < sixPriceMin
		|| (n < 6 && onePriceMin * n < sixPriceMin))
		totalPrice = onePriceMin * n;
	else if (sixPriceMin < onePriceMin
		|| sixPriceMin * ((n + 5) / 6) < sixPriceMin * (n / 6) + onePriceMin * (n % 6))
		totalPrice = sixPriceMin * ((n + 5) / 6);
	else
		totalPrice = sixPriceMin * (n / 6) + onePriceMin * (n % 6);
	cout << totalPrice;
	return 0;
}