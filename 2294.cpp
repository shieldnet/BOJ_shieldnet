#include <cstdio>
#include <iostream>

using namespace std;

int dp[10001], n, k;
const int MAX = 987654321;

int main() {
	scanf("%d %d", &n, &k);

	//모든 방법의 개수를 MAX개로 초기화해줍니다.
	for (int i = 1; i <= k; i++) {
		dp[i] = MAX;
	}

	for (int i = 0; i < n; i++) {
		int c;

		scanf("%d", &c);

		for (int j = c; j <= k; j++) {
			if (dp[j] > dp[j - c] + 1) {
				dp[j] = dp[j - c] + 1;
			}
		}
	}

	printf("%d", dp[k] == MAX ? -1 : dp[k]);
	return 0;
}