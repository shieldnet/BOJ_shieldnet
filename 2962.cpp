#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>

const int MAXN = 100;

int t, n, m;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int f(int, int, int);
int getans(int, int*, int*, int);
int binsearch(int);
int solve();

int main(void) {
	scanf("%d", &t);
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d%d", &c[i], &d[i]);

	printf("%d\n", solve());
	return 0;
}

int f(int v, int x, int y) {
	if (v < x) return 0;
	return (v - x) / y + 1;
}

int getans(int v, int *x, int *y, int q) {
	int ret = 0;
	for (int i = 0; i < q; ++i) ret += f(v, x[i], y[i]);
	return ret;
}

int binsearch(int v) {
	return getans(v, a, b, n) <= getans(t - v, c, d, m);
}

int solve() {
	int l = 1, r = t;
	while (r - l > 1) {
		int tt = (l + r) / 2;
		if (binsearch(tt)) l = tt;
		else r = tt;
	}
	return l;
}