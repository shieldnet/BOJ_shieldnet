#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		ans += temp;
	}
	ans -= (n - 1);

	printf("%d", ans);

}