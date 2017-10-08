#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<vector<long long>> matrix;
const LL mod = 1000000007;

matrix operator* (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

int main() {
	LL n;

	cin >> n;

	matrix ans = { { 1, 0 },{ 0, 1 } };
	matrix a = { { 1, 1 },{ 1, 0 } };

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1];

	return 0;
}