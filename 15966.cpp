#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> v(n+1), dp(n+1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		scanf("%d", &v[i]);
		for (int j = 0; j < i; j++) {
			if (v[j] == v[i] - 1) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		ans = std::max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}