#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int mapsize[16] = { 1 };

int Z(int, int, int);

int main() {
	int N, R, C;
	for (int i = 1; i < 16; i++) {
		mapsize[i] = mapsize[i - 1] * 2;
	}

	while (scanf("%d %d %d", &N, &R, &C) > 0) {
		printf("%d\n", Z(N, R, C) - 1);
	}
}

int Z(int n, int r, int c) {
	if (n == 0) return 1;

	if (r < mapsize[n - 1]) {
		if (c < mapsize[n - 1]) return Z(n - 1, r, c);
		else return mapsize[n - 1] * mapsize[n - 1] + Z(n - 1, r, c - mapsize[n - 1]);
	}
	else {
		if (c < mapsize[n - 1]) return mapsize[n - 1] * mapsize[n - 1] * 2 + Z(n - 1, r - mapsize[n - 1], c);
		else return mapsize[n - 1] * mapsize[n - 1] * 3 + Z(n - 1, r - mapsize[n - 1], c - mapsize[n - 1]);
	}
}