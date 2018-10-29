#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001] = { 0, };
int dp[100001] = { 0, };

int main() {
	int n;	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int ans = -1e9;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}