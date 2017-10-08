#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

bool isVisited[1001] = { false, };
int map[1001][1001] = { 0, };
int n, m, v;


void dfs(int vertex) {
	isVisited[vertex] = true;
	for (int i = 1; i <= n; i++) {
		if (map[vertex][i] && !isVisited[i]) {
			printf("%d ", i);
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		map[r][c] = 1;
	}

	printf("%d ", v);
	dfs(v);

	


	return 0;
}