#define _CRT_SECURE_NO_WARNIGNS 
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>
using namespace std;

using namespace std;

class Point {
public:
	int x, y, dir, cmd;
	Point() {}; Point(int _x, int _y, int _dir, int _cmd) :x(_x), y(_y), dir(_dir), cmd(_cmd) {};
};

int m[101][101];
int isVisited[101][101][5];
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

int getOpposite(int n) {
	if (n == 1)return 2;
	if (n == 2)return 1;
	if (n == 3)return 4;
	if (n == 4)return 3;
}

int main() {
	int R, C; cin >> R >> C;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf("%d", &m[i][j]);
		}
	}

	int si, sj, sdir, ei, ej, edir;

	cin >> si >> sj >> sdir >> ei >> ej >> edir;
	queue<Point> q;

	memset(isVisited, -1, sizeof(isVisited));

	q.push(Point(si, sj, sdir, 0));

	isVisited[si][sj][sdir] = 1;

	//bfs
	while (!q.empty()) {
		Point h = q.front(); q.pop();
		int hi = h.x; int hj = h.y; int hdir = h.dir; int hc = h.cmd;
		int ni, nj;
		if (hi == ei&&hj == ej&&hdir == edir) {
			cout << hc << endl;
			break;
		}
		for (int i = 1; i <= 3; ++i) {
			ni = hi + dx[hdir] * i;
			nj = hj + dy[hdir] * i;
			if (ni < 1 || ni > R || nj < 1 || nj > C || m[ni][nj] == 1)break;
			if (isVisited[ni][nj][hdir] == 1)continue;
			isVisited[ni][nj][hdir] = 1;
			q.push(Point(ni, nj, hdir, hc + 1));
		}
		for (int i = 1; i <= 4; ++i) {
			if (i == hdir || i == getOpposite(hdir))continue;
			if (isVisited[hi][hj][i] == 1)continue;
			isVisited[hi][hj][i] = 1;
			q.push(Point(hi, hj, i, hc + 1));
		}
	}
	return 0;
}