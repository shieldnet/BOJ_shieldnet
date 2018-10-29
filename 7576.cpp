#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int mp[1000][1000] = { 0, };
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0 ,1,-1 };
queue< pair<int, int> > q;

int main() {
	int n,m; scanf("%d%d", &m,&n);
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			scanf("%d", &mp[r][c]);
			if (mp[r][c] == 1) {
				q.push(pair<int,int>(r,c));
			}
		}
	}

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		int y = now.first, x = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (mp[ny][nx] == 0) {
				mp[ny][nx] = mp[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}

	int mx = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 0) {
				printf("%d", -1);
				return 0;
			}
			mx = max(mx, mp[i][j]);
		}
	}

	printf("%d", mx - 1);



	return 0;
}