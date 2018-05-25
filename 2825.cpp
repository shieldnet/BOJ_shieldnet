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
typedef long double LD;
typedef pair<LL, LL> pll;


LL bitcompress(LL num) {
	LL ret = 0;
	while (num > 0) {
		ret = ret | (1<<(num%10));
		num /= 10;
	}
	return ret;
}

int main(void)
{
	LL compressed[1025] = { 0, };
	LL n = 0;
	LL ans = 0;

	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		LL num;
		scanf("%lld", &num);
		LL cmpressed = bitcompress(num);
		compressed[cmpressed]++;
	}

	for (int i = 0; i<1025; i++) {
		ans += (compressed[i] * (compressed[i] - 1)) / 2;
		for (int j = i + 1; j < 1025; j++) {
			if (i&j) {
				ans += compressed[i] * compressed[j];
			}
		}
	}


	printf("%lld", ans);
	

	return 0;
}

