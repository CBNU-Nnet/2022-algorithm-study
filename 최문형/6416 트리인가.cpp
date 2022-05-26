#include <iostream>
#include <queue>
#include <deque>
#include <map>

using namespace std;
map<int, int> indegree, outdegree;

bool is_tree_bfs(map<int, deque<int>>& tree, int root) {
	map<int, bool> visited;
	queue<int> q;

	q.push(root);
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (auto i : tree[front]) {
			if (visited[i]) {
				return false;
			}

			visited[i] = true;
			q.push(i);
		}
	}


	return true;
}

int find_root() {
	int root = -1;
	
	int indegree_zero_cnt = 0;
	for (auto i : outdegree) {	
		// indegree가 0인 친구들이 root의 후보임.
		if (indegree[i.first] == 0) {
			// but, root가 2개일 순 없기에 예외처리를 따로 함.
			if (indegree_zero_cnt == 1) {
				return -1;
			}

			indegree_zero_cnt++;
			root = i.first; // 트리의 root 설정 
		}
	}

	// 트리 노드 번호를 리턴함.
	return root;
}

int main() {
	map<int, deque<int>> tree;
	int case_num = 1;
	int u, v;

	bool input_finish = false;
	while (1) {
		tree.clear();
		indegree.clear();
		outdegree.clear();

		int node_cnt = 0;
		while (1) {
			cin >> u >> v;
			if (u == -1 && v == -1) {
				input_finish = true;
				break;
			}

			if (u == 0 && v == 0) {
				break;
			}
			
			// v 노드로 들어온 적도 없고, u 노드로 나간 적이 없다면
			if (!indegree[v] && !outdegree[u]) {				
				node_cnt++; // 해당 노드는 새 노드임.
			}

			// u ==> v  이므로 indegree는 v, outdegree는 u임.
			indegree[v]++;
			outdegree[u]++;

			// 인접리스트로 graph를 만듦.
			tree[u].push_back(v);
		}

		if (input_finish) {
			break;
		}

		// 아무 노드도 없을 때도 tree이므로 is_tree를 true로 설정
		bool is_tree = true;
		int root = 0;
		if (node_cnt) {
			// root 가 없거나 2개 이상일 경우, -1 
			root = find_root();

			// tree의 루트가 존재한다면, bfs 수행
			if (root != -1) {
				is_tree = is_tree_bfs(tree, root);
			}
		}

		cout << "Case " << case_num << " is";
		if (!is_tree || root == -1) {
			cout << " not";
		}
		cout << " a tree.\n";

		case_num++;
	}

	return 0;
}
