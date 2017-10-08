#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int a[10002] = { 0, };
int dp[10002] = { 0, };


int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(int) * 10002);
	dp[0] = 0;
	a[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = max(a[1] + a[2], max(a[1] + a[3], a[2] + a[3]));

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[n-2]+a[n],max(dp[i - 1], dp[i - 3] + a[i] + a[i - 1]));
	}

	cout << dp[n];



	return 0;
}