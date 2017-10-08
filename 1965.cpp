#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	LL n;
	cin >> n;
	vector<LL> v;
	int cache[1001] = { 0, };
	for (int i = 0; i < n; i++) {
		LL temp;
		scanf("%lld", &temp);
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		cache[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j]<v[i] && cache[j] + 1>cache[i]) {
				cache[i] = cache[j] + 1;
			}
		}
	}
	LL large = 0;
	for (int i = 0; i < n; i++) {
		large = max(large, (LL)cache[i]);
	}

	cout << large;


	return 0;
}