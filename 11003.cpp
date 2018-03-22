#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long LL;

LL l, n, x;

deque<pair<LL, LL>> windows;

int main() {

	scanf("%lld%lld", &n, &l);

	for (int i = 1; i <= n; i++) {
		while (windows.size() && windows.front().second <= i - l) windows.pop_front();

		scanf("%lld", &x);
		while (windows.size() && windows.back().first >= x)
			windows.pop_back();
		windows.push_back({ x,i });
		printf("%lld ", windows.front().first);
	}
	return 0;
}