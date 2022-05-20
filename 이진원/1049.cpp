/*
* Problem: 1049
* Solver: Jinwon
* Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, brokenString, brandCnt, priceBySet, priceByOne;
	int minSetPrice = 1001, minOnePrice = 1001;
	int sum = 0;

	cin >> brokenString >> brandCnt;

	for (i = 0; i < brandCnt; i++) {

		cin >> priceBySet >> priceByOne;

		minSetPrice = priceBySet < minSetPrice ? priceBySet : minSetPrice;
		minOnePrice = priceByOne < minOnePrice ? priceByOne : minOnePrice;
	}

	if (minSetPrice > minOnePrice * 6)
		sum += minOnePrice * brokenString;
	else {
		sum += minSetPrice * (brokenString / 6);
		if (minSetPrice < minOnePrice * (brokenString % 6))
			sum += minSetPrice;
		else
			sum += minOnePrice * (brokenString % 6);
	}

	cout << sum;
}