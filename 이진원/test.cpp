/*
* Problem: 7511
* Solver: Jinwon
* Reference: https://littlesam95.tistory.com/148
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findparent(int child);
void input(int T);

vector<int> parent;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, i;

	cin >> T;

	for (i = 0; i < T; i++) {
		
		input(i+1);
	}

	return 0;
}

int findparent(int child) {
	if (parent[child] == -1 || parent[child] == child) {
		return child;
	}
	else
		return findparent(parent[child]);
}



void input(int T) {

	int i, a, b, userNum, relationshipNum, pairNum, pa, pb;
	queue<pair<int, int>> pairs;

	cin >> userNum;

	parent.clear();
	parent.assign(userNum, -1);

	cin >> relationshipNum;
	for (i = 0; i < relationshipNum; i++) {
		cin >> a >> b;

		pa = findparent(a);
		pb = findparent(b);

		parent[pa] = pb;
	}

	cin >> pairNum;
	for (i = 0; i < pairNum; i++) {

		cin >> a >> b;
		pairs.push({ a,b });
	}

	cout << "Scenario " << T << ":\n";
	while(!pairs.empty()) {

		if (findparent(pairs.front().first) == findparent(pairs.front().second))
			cout << "1\n";
		else
			cout << "0\n";

		pairs.pop();
	}
	cout << "\n";
}