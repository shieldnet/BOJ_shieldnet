#include <functional>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

typedef long long LL;

using namespace std;
int main() {

	int n, k; scanf("%d%d", &n, &k);
	vector<int> v(n);
	priority_queue<LL, vector<LL>, greater<LL> > h;
	int conti = 0;
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	for (int i = 1; i < v.size();i++) {
		if (v[i] - v[i - 1] - 1 != 0) h.push(v[i] - v[i - 1] - 1);
		else conti++;
	}
	int t = n - conti - k;
	while (t-- >0) {
		n += h.top();
		h.pop();
	}

	printf("%d", n);
	return 0;
}