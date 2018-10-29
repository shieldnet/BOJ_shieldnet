#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[51][51], r;
char b;
int main() {
	scanf("%d", &n);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++) {
			scanf("%c", &b);
			if (b == 'Y')a[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++)
				if (a[j][i] + a[i][k] < a[j][k])
					a[j][k] = a[j][i] + a[i][k];
		}
	}
	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			s += a[i][j] < 3 ? 1 : 0;
		}
		r = max(r, s);
	}
	printf("%d\n", r);
	return 0;
}