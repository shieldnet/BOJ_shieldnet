#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		char c = getchar();
		ans += (c - '0');
	}
	printf("%d", ans);
	return 0;
}