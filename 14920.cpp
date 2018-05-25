#define _CRT_SECURE_NO_WARNINGS
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

int main(void)
{
	LL n, cnt = 1;
	scanf("%lld", &n);
	while (n != 1) {
		if (n & 1) n = 3 * n + 1;
		else n /= 2;

		cnt++;
	}
	printf("%lld", cnt);
	return 0;
}
