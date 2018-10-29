#include <cstdio>
#include <algorithm>
using namespace std;

int sq[55][55] = { 0, };

int main() {
	int n, m,ans=0; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &sq[i][j]);
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			for (int d = 0; d < min(n, m); d++) {
				if (r + d >= n || c + d >= m) {
					break;
				}
				if (sq[r][c] == sq[r + d][c] && sq[r + d][c] == sq[r + d][c + d] && sq[r + d][c + d] == sq[r][c + d]) {
					ans = max(ans, (d + 1)*(d + 1));
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}