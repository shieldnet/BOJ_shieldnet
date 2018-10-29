#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int dy[4] = { 0,0,-1,1 };
const int dx[4] = { 1,-1,0,0 };
int m, n, k;
void dfs(int r, int c, int mp[][50]) {
	if (mp[r][c] == 0) return;
	mp[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = r + dy[i], nx = c + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		dfs(ny, nx, mp);
	}
	return;
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int mp[50][50];
		memset(mp, 0, sizeof(mp));
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0;i<k; i++){ 
			int row, col; scanf("%d%d", &col, &row);
			mp[row][col] = 1;
		}
		int ans = 0;
		for (int r = 0; r<n; r++) {
			for (int c = 0; c < m; c++) {
				if (mp[r][c] == 1) {
					dfs(r, c, mp);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}