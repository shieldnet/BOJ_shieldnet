#include<cstdio>
#include<cmath>
typedef long long ll;
int main() {
	int tc;
	for (scanf("%d", &tc); tc > 0; tc--) {
		ll x1, x2;
		scanf("%lld%lld", &x1, &x2);
		ll dist = x2 - x1;
		for (ll i = 1; i < 50000; i++) {
			ll n2 = i*i;
			ll rem = ceil((dist - n2) / (float)i);
			ll mn = 2 * i - 1;

			if (n2 <= dist && dist < (i + 1)*(i + 1)) {
				printf("%lld\n", mn + rem);
				break;
			}
		}
	}
	return 0;
}