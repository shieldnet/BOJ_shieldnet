#include <cstdio>
using namespace std;
int gcd(int a, int b) {
	while (b) {
		int t = a%b; a = b; b = t;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b)*b;
}

int main() {
	int tc = 1;
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		printf("%d\n%d", gcd(n, m), lcm(n, m));
	}
	return 0;
}