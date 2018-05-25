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
typedef long long LL;

LL n, cost;
LL m[1313] = { 0, };
LL c[1313] = { 0, };
LL cache[112][10123] = { 0, };

LL solve(LL,LL);

int main() {
	scanf("%lld%lld", &n, &cost);

	LL lo = 0, hi = 0;

	for (LL i = 0; i < n; i++) {
		scanf("%lld", &m[i]);
	}

	for (LL i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
		hi += c[i];
	}

	memset(cache, -1, sizeof(cache));


	//분할정복
	while (lo < hi) {
		LL mid = (lo + hi) >> 1;
		if (solve(n - 1, mid) >= cost)
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", lo);
	return 0;
}

LL solve(LL pos, LL cos) {

	if (pos < 0) {
		return 0;
	}
	LL &ret = cache[pos][cos];

	if (ret != -1) {
		return ret;
	}

	ret = solve(pos - 1, cos);

	if (cos - c[pos] >= 0) {
		ret = max(ret, solve(pos - 1, cos - c[pos]) + m[pos]);
	}

	return ret;
}