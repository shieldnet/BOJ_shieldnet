#include<cstdio>

const int fx[] = { 0,1,0,-1 }, fy[] = { 1,0,-1,0 };
int m, n, r;
char c[1000][1001];

void f(int x, int y) {
	r |= x == m;
	if (x < 0 || y < 0 || x == m || y == n || c[x][y] == '1') return;
	c[x][y] = '1';
	for (int i = 0; i < 4; i++) f(x + fx[i], y + fy[i]);
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) scanf("%s", c[i]);
	for (int i = 0; i < n; i++) f(0, i);
	puts(r ? "YES" : "NO");
	return 0;
}
