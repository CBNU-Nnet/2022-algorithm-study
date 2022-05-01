#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// 유니온 파인드의 find 연산
int _find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = _find(parent[x]);
}

// 유니온 파인드의 union 연산
void _union(int x, int y) {
	int a = _find(x);
	int b = _find(y);

	if (a == b) {
		return;
	}

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}


int main() {
	// cpp 에선 입출력이 느리기 때문에 아래의 코드를 따로 작성해줘야 한다.
	// 특히나 이 문제에선 아래의 코드를 적지 않을경우, '무조건' 시간초과가 뜬다...
	cin.tie(0);  cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int scenario = 1; scenario <= t; scenario++) {
		cout << "Scenario " << scenario << ":\n";

		int n, k;
		cin >> n >> k;

		// union_find; 
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}

		// 친구 연결하기
		for (int i = 0; i < k; i++) {
			int a, b;

			cin >> a >> b;

			_union(a, b);
		}

		// 친구 확인하기
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;

			cin >> a >> b;
				
			if (_find(a) == _find(b)) { // a와 b가 같은 set에 있다 == 친구 관계 그래프상에 경로가 존재
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		cout << "\n";
	}
}
