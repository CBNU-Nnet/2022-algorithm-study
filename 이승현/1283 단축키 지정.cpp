#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> words;
	vector<char> shortcuts;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{

		string word;
		getline(cin, word);
		words.push_back(word);
	}

	for (int i = 0; i < words.size(); i++) // for (string var in words)로 반복하고 싶었으나 var이 words 요소들을 복제한 거라서 값 변경이 안 되는 듯
	{
		if (find(shortcuts.begin(), shortcuts.end(), tolower(words[i][0])) == shortcuts.end())
		{
			shortcuts.push_back(tolower(words[i][0]));
			words[i] = "[" + words[i].substr(0, 1) + "]" + words[i].substr(1);
		}
		else if (words[i].find(" ") != string::npos)
		{
			int index = 0;
			while (index != string::npos)
			{
				index = words[i].find(" ", index + 1);
				if (find(shortcuts.begin(), shortcuts.end(), tolower(words[i][index + 1])) == shortcuts.end())
				{
					shortcuts.push_back(tolower(words[i][index + 1]));
					words[i] = words[i].substr(0, index + 1) + "[" + words[i][index + 1] + "]" + words[i].substr(index + 2);
					break;
				}
			}
		}
		else
		{
			for (int j = 0; j < words[i].length(); j++)
			{
				if (find(shortcuts.begin(), shortcuts.end(), tolower(words[i][j])) == shortcuts.end())
				{
					shortcuts.push_back(tolower(words[i][j]));
					words[i] = words[i].substr(0, j) + "[" + words[i].substr(j, 1) + "]" + words[i].substr(j + 1);
					break;
				}
			}
		}
	}

	for (string word : words)
	{
		cout << word << endl;
	}
	return 0;
}