#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
typedef long long LL;

int s[maxn][maxn];

int n, m, t, p, sx, sy, ex, ey;

int main() {
	int _;
	int d, c, x, y;
	while (scanf("%d %d %d %d", &n, &m, &t, &p) != EOF) {
		if (n == 0 && m == 0 && t == 0 && p == 0) break;
		ex = n, ey = m;
		sx = 0, sy = 0;
		memset(s, 0, sizeof(s));
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				s[i][j] = 1;
		while (t--) {
			scanf("%d %d", &d, &c);
			if (d == 1) {
				for (int i = 0; i < c; i++) {
					for (int j = sy; j <= ey; j++) {
						s[sx + c + i][j] += s[sx + c - i - 1][j];
					}
				}
				ex = max(ex, sx + c + c);
				sx += c;
			}
			else {
				for (int i = sx; i <= ex; i++) {
					for (int j = 0; j < c; j++) {
						s[i][sy + c + j] += s[i][sy + c - j - 1];
					}
				}
				ey = max(ey, sy + c + c);

				sy += c;
			}
		}
		int ans = 0;
		while (p--) {
			scanf("%d %d", &x, &y);
			printf("%d\n", s[sx + x][sy + y]);

		}
	}
	return 0;
}