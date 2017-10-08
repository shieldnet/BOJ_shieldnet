#define INF 987654321

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[205][205] = { 0, };
vector<int> v;



int main() {
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			scanf("%d", &map[r][c]);
		}
	}

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (map[r][c] == 1) {
				map[c][r] = 1;
			}
			if (map[c][r] == 1) {
				map[r][c] = 1;
			}

			if (map[r][c] == 0) {
				map[r][c] = INF;
			}
		}
	}


	//floyd
	for (int k = 1; k<=n; k++)
		for (int i = 1; i<=n; i++)
			for (int j = 1; j<=n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);


	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			map[r][c] = (map[r][c] == INF ? 0 : 1);
		}
	}


	//path input
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	for (int i = 0; i < v.size()-1; i++) {
		if (map[v[i]][v[i + 1]] || v[i]==v[i+1]) {
			continue;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
	


	return 0;
}