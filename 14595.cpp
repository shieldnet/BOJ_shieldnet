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

int main(){
	LL n, m;
	scanf("%lld", &n);
	scanf("%lld", &m);
	LL wall[1000001] = { 0, };
	while (m--) {
		LL from, to;
		scanf("%lld%lld", &from, &to);
		wall[from]++;
		wall[to]--;
	}
	LL partial_sum[1000001] = { 0, };
	partial_sum[0] = wall[0];
	for (int i = 1; i < 1000001; i++) {
		partial_sum[i] = partial_sum[i - 1] + wall[i];
	}
	LL corrupted = 0;
	for (int i = 0; i < 1000000; i++) {
		if (partial_sum[i] > 0)corrupted++;
	}
	printf("%lld", n - corrupted);
	return 0;
}

