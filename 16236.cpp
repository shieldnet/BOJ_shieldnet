#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
typedef long long LL;


int n;
int mp[22][22] = { 0, };
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

pair<int, int> getFishFrom(int y, int x) {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {

		}
	}
}

int bfs(int f_y, int f_x, int d_y, int d_x, int sz) {
	if (f_y < 0 || f_x < 0 || f_y >= n || f_x >= n) { return 0; }
	if (f_y == d_y && f_x == d_x) return 0;
	if (mp[f_y][f_x] > sz) {

	}

}

int main() {

	scanf("%d", &n);

	return 0;
}