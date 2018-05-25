#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int a[10002] = { 0, };
int cache[10002] = { 0, };


int main() {
	int n;
	cin >> n;
	memset(cache, -1, sizeof(int) * 10002);
	cache[0] = 0;
	a[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cache[1] = a[1];
	cache[2] = a[1] + a[2];
	cache[3] = max(a[1] + a[2], max(a[1] + a[3], a[2] + a[3]));

	for (int i = 3; i <= n; i++) {
		cache[i] = max(cache[n-2]+a[n],max(cache[i - 1], cache[i - 3] + a[i] + a[i - 1]));
	}

	cout << cache[n];



	return 0;
}