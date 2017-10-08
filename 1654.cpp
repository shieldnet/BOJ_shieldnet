#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

int k, n;

LL lan[10010];

LL getlan(int t) {
	LL cnt = 0;
	for (int i = 0; i < k;i++) {
		cnt += (lan[i] / t);

	}

	return cnt;
}

LL result(LL s, LL e) {
	LL m = (s + e + 1) / 2;
	if (s == m) return m;
	if (getlan(m) >= n) {
		if (getlan(m + 1) < n) return m;
		return result(m + 1, e);

	}
	else result(s, m - 1);
}


int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) scanf("%lld", &lan[i]);
		
	printf("%lld", result(0, 2147483647));

	return 0;
}