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

#define BIGGEST 100000

LL A, B, X;
int dekiru_numbers[10];

LL memo[12][BIGGEST][2];

LL log10(int, LL);

int main(void) {
	scanf("%lld %lld %lld", &X, &A, &B);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		dekiru_numbers[s[i] - '0'] = 1;
	}

	LL ans = 0;

	if (X >= BIGGEST) {
		for (LL x = X; x <= B; x += X) {
			int cool = 1;
			for (LL y = x; cool && y; y /= 10) cool &= dekiru_numbers[y % 10];
			if (cool && x >= A) ++ans;
		}
	}
	else {
		memset(memo, -1, sizeof(memo));
		ans = log10(11, 0);
	}

	printf("%lld\n", ans);

	return 0;
}

LL log10(int n, LL forward) {

	LL maxi = forward, mini = forward;
	for (int i = 0; i < n; ++i) maxi = maxi * 10 + 9;
	for (int i = 0; i < n; ++i) mini = mini * 10 + 0;

	if (maxi < A || mini > B) return 0;
	if (n == 0) return forward%X == 0;

	int memoize = mini >= A && maxi <= B;

	LL & ref = memo[n][forward%X][forward == 0];
	if (memoize && ref >= 0) return ref;

	LL ret = 0;
	for (int dig = 0; dig < 10; ++dig)
		if (dekiru_numbers[dig] || dig == 0 && forward == 0)
			ret += log10(n - 1, forward * 10 + dig);

	if (memoize) ref = ret;

	return ret;
}