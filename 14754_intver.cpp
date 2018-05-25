#include <iostream>
#include <cstdio>

using namespace std;

int map[1001][1001] = { 0, };
bool check[1001][1001] = { false, };

int main() {
	int n, m;
	int answer = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//Row
	for (int i = 0; i < n; i++) {
		int maxval = -1;
		int maxpos = -1;
		for (int j = 0; j < m; j++) {
			if (map[i][j] >= maxval) {
				maxpos = j;
				maxval = map[i][j];
			}
		}
		for (int j = 0; j < m; j++) {
			if (j == maxpos) check[i][j] = true;
		}
	}

	//Col
	for (int i = 0; i < m; i++) {
		int maxval = -1;
		int maxpos = -1;
		for (int j = 0; j < n; j++) {
			if (map[j][i] >= maxval) {
				maxpos = j;
				maxval = map[j][i];
			}
		}
		for (int j = 0; j < n; j++) {
			if (j == maxpos) check[j][i] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer += check[i][j] ? 0 : map[i][j];
		}
	}

	printf("%d", answer);
	return 0;
}