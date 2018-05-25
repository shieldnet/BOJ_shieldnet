#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
int main() {
	LL x, y, z;
	LL lo, hi;
	while (scanf("%lld %lld", &x, &y) > 0) {
		z = 100 * y / x;
		if (z >= 99) {
			printf("-1\n");
			continue;
		}

		lo = 1;
		hi = x;
		while (lo < hi) {
			LL mid = (lo + hi) / 2;

			if (100 * (y + mid) / (x + mid) > z) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		printf("%lld\n", hi);

	}
}
