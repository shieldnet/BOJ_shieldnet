#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[101][101] = { 0, };
int visit[101][101] = { 0, };
const int dy[4] = { 0,0,-1,1 };
const int dx[4] = { 1,-1,0,0 };

int n, m;

int bfs(int, int);

int main() {
	memset(visit, -1, sizeof(visit));
	cin >> n >> m;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			int temp;
			scanf("%1d", &temp);
			map[r][c] = temp;
		}
	}

	cout << bfs(0, 0);

	return 0;
}

int bfs(int r,int c) {
	int ans = 0;
	int cango = 0;
	if (r < 0 || c<0 || r>n - 1 || c>m - 1) return 0;
	if (r == n - 1 && c == m - 1) {
		return 1;
	}
	if (visit[r][c] != -1) {
		return 0;
	}
	visit[r][c] = 1;
	
	return cango;
	for (int i = 0; i < 4; i++) {
		ans += cango;
		ans += min(ans,bfs(r + dy[i], c + dx[i]));
	}
}