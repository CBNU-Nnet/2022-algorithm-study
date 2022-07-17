#include <iostream>
#include <vector>
#define MOD 1000

using namespace std;
using lld = long long;

vector<int> M, c;
int n;
lld depth;

void dot_product(vector<int> a, vector<int> b) {

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			c[k * n + i] = 0;

			for (int j = 0; j < n; j++) {
				c[k * n + i] += a[k * n + j] * b[j * n + i];
			}
			c[k * n + i] %= MOD;
		}
	}
}

void pow_matrix(lld depth) {
	if (depth == 1) {
		c = M;
		return;
	}
	if (depth == 2) {
		dot_product(M, M);
		return;
	}
	pow_matrix(depth / 2);
	dot_product(c, c);
	if (depth % 2 == 1) {
		dot_product(c, M);
	}
	return;
}

int main() {
	cin >> n >> depth;

	c.assign(n * n, 0);
	M.assign(n * n, 0);
	for (int i = 0; i < n * n; i++) {
		cin >> M[i];
		M[i] %= 1000;
	}

	pow_matrix(depth);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c[i * n + j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
