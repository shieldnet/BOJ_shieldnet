#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int visited[20010] = { 0, };
int map[20010][20010] = { 0, };
int judge = 1;
int n, m;
int cnt[20010] = { 0, };

void dfs(int);

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);

		for (int i = 0; i < m; i++) {
			int r, c;
			scanf("%d%d", &r, &c);
			map[r][c] = map[c][r] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] != 0) {
				continue;
			}
			judge++;
			dfs(i);
		}
		for (int i = 0; i <= n; i++) {
			cnt[visited[i]]++;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			if (cnt[i] != 0)ans++;
		}
		if (ans == 2) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		memset(cnt, 0, sizeof(cnt));

	}
	return 0;
}

void dfs(int v) {
	visited[v] = judge;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && map[v][i]) {
			dfs(i);
		}
	}

}