#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<int> VI;
typedef vector< VI > VVI;

const int dx[4] = { -1,+1,0,0 };
const int dy[4] = { 0,0,+1,-1 };
int n, L, R;
bool flag = false;

void avg(VVI& v, VVI& uni, int val) {
	int sum = 0;
	int cnt = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (uni[r][c] == val) {
				sum += v[r][c];
				cnt++;
			}
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (uni[r][c] == val) {
				v[r][c] = (sum / cnt);
			}
		}
	}
}

int bfs(int r, int c,int unit, VVI& v, VVI& uni) {
	if (uni[r][c] != -1) return 0;
	uni[r][c] = unit;
	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
		if (abs(v[r][c] - v[nr][nc]) <= R && abs(v[r][c] - v[nr][nc]) >= L) {
			flag = true;
			bfs(nr, nc, unit, v, uni);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &L, &R);
	VVI v(n, VI(n, 0));
	VVI uni(n, VI(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	int cnt = 0;
	int unit = 0;
	while (true) {
		flag = false;
		for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) uni[r][c] = -1;
		
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				unit++;
				bfs(r, c, unit, v, uni);
				avg(v, uni, unit);
			}
		}
		if (!flag) { break; }
		if (flag) { cnt++; };
	}
	printf("%d", cnt);
	return 0;
}