#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	for (int k = 0; k < 10101; k++) {
		if ((1 + k + k*k) == n) printf("%d", k);
	}
	return 0;
}