#include <cstdio>
#include <algorithm>
#define MAXX 1000
using namespace std;
int n, m, x, y, a, b;
int main() {
	scanf("%d%d", &n, &m);
	a = b = MAXX;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		a = min(x, a);
		b = min(y, b);
	}
	if (a > 6 * b)
		a = 6 * b;
	if ((n % 6)*b > a)
		printf("%d\n", (n / 6)*a + a);
	else
		printf("%d\n", (n / 6)*a + (n % 6)*b);
	return 0;
}