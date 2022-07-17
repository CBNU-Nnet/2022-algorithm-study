#include<iostream>
#include <set>
using namespace std;

int main()
{
	string s;
	set<string> subStr;
	cin >> s;
	for (int subStrLength = 1; subStrLength <= s.length(); subStrLength++)
	{
		for (int offset = 0; offset + subStrLength <= s.length(); offset++)
		{
			subStr.insert(s.substr(offset, subStrLength));
		}
	}
	cout << subStr.size();
	return 0;
}