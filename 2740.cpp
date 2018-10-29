#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector< vector<LL> > Matrix;

Matrix operator* (const Matrix& a, const Matrix& b) {
	int n = a.size();
	int m = a[0].size();
	int l = b[0].size();
	Matrix c(n, vector<LL>(l));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < m; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Matrix a(n, vector<LL>(m));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			scanf("%d", &a[r][c]);
		}
	}
	scanf("%d%d", &n, &m);
	Matrix b(n, vector<LL>(m));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			scanf("%d", &b[r][c]);
		}
	}
	Matrix ret = a*b;
	for (int r = 0; r < ret.size(); r++) {
		for (int c = 0; c < ret[0].size(); c++) {
			printf("%d ", ret[r][c]);
		}
		printf("\n");
	}
	return 0;
}