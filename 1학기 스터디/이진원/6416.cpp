/*
* Problem: 6416
* Solver: Jinwon
* Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void DFS(map<int, vector<int>> edgeList, map<int, bool>& visited, int node);

bool istree = true;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rootNode, u = 0, v = 0, rootCnt = 0, testNum = 0;
	map<int, vector<int>> edgeList;
	map<int, bool> nodeInEdge; // 들어오는 간선이 있으면 true
	map<int, bool> visited;
	map<int, bool>::iterator iter;

	cin >> u >> v;

	while (u > -1 && v > -1) {

		edgeList.clear();
		nodeInEdge.clear();
		visited.clear();

		rootCnt = 0;
		istree = true;

		testNum++;

		while (u > 0 && v > 0) {

			edgeList[u].push_back(v);

			nodeInEdge.insert({ u,false }); // insert는 이미 존재시 수행하지 않음
			nodeInEdge[v] = true;

			visited[u] = false;
			visited[v] = false;

			cin >> u >> v;
		}

		// 루트 찾기
		for (iter = nodeInEdge.begin(); iter != nodeInEdge.end(); iter++) {
			if (!(iter->second)) {
				rootCnt++;
				rootNode = iter->first;
			}
		}
				
		
		// 트리 판정
		if (rootCnt != 1 && !edgeList.empty())
			istree = false;
		else {
			// 중복 방문 여부
			visited[rootNode] = true;
			DFS(edgeList, visited, rootNode);

			// 모든 노드 방문
			for (iter = visited.begin(); iter != visited.end(); iter++)
				if (!(iter->second))
					istree = false;
		}



		if (istree)
			cout << "Case " << testNum << " is a tree.\n";
		else
			cout << "Case " << testNum << " is not a tree.\n";

		cin >> u >> v;
	}
}

void DFS(map<int, vector<int>> edgeList, map<int, bool>& visited, int node) {

	int next;

	while (!edgeList[node].empty()) {

		next = edgeList[node].back();

		if (!visited[next]) {

			visited[next] = true;
			DFS(edgeList, visited, next);
		}
		else
			istree = false;

		edgeList[node].pop_back();
	}
}