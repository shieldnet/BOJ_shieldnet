#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
	bool map[105][105] = { false, };
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int r = y; r < 10+y; r++) {
			for (int c = x; c < x+10; c++) {
				map[r][c] = true;
			}
		}
	}
	int ans = 0;
	for (int r = 0; r < 101; r++) {
		for (int c = 0; c < 101; c++) {
			if (map[r][c]) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}