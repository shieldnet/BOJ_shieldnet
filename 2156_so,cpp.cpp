#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
int dp[10005][4];
int a[10005];
int n;

int rec(int x, int y)
{
	if (y >= 3)return -INF;
	if (x>n)return 0;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 0;
	ret = max(ret, a[x] + rec(x + 1, y + 1));
	ret = max(ret, rec(x + 1, 0));
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d",rec(0,0));
}