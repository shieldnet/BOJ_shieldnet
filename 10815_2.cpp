#include <cstdio>
#include <algorithm>

using namespace std;
int from[500000];//가지고 있는것
int to[500000];//구해야 하는 거
int n;
int m;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &from[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &to[i]);
	}
	sort(from, from + n);

	printf("%d",(upper_bound(from,from+n,to[0]) - lower_bound(from, from+n,to[0])));
	for (int i = 1; i < m; i++) {
		printf(" %d", (upper_bound(from, from + n, to[i]) - lower_bound(from, from + n, to[i])));
	}
	return 0;
}