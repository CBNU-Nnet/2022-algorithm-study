#include <iostream>

using namespace std;

struct node {
	int key;
	node* left_child;
	node* right_child;
};

node* root = new node;

void insert(int insert_key) {
	node* parent = root;
	bool is_insert_left = true;

	while (1) {
		if (parent->key < insert_key) { // 오른쪽 자식 
			if (parent->right_child == NULL) {
				is_insert_left = false;
				break;
			}

			parent = parent->right_child;
		}

		else {
			if (parent->left_child == NULL) {
				break;
			}

			parent = parent->left_child;
		}
	}

	node* insert_node = new node;
	insert_node->key = insert_key;
	insert_node->right_child = insert_node->left_child = NULL;

	if (is_insert_left) {
		parent->left_child = insert_node;
	}
	else {
		parent->right_child = insert_node;
	}
}

void post_order(node* parent) {
	if (parent->left_child) {
		post_order(parent->left_child);
	}
	if (parent->right_child) {
		post_order(parent->right_child);
	}
	cout << parent->key << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int key;
	cin >> key;
	
	root->key = key;
	root->left_child = NULL;
	root->right_child = NULL;

	while (1) {
		cin >> key;

		if (cin.eof()) {
			break;
		}

		insert(key);
	}

	post_order(root);

	return 0;
}
