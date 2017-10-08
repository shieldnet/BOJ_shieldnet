#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

bool cmp(pair<LL, LL> a, pair<LL, LL> b) {
	if (a.first < b.first) {
		return true;
	}
	return false;
}

int main() {
	LL n;
	vector< pair<LL, LL> > v;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		LL first, second;
		scanf("%lld %lld", &first, &second);
		v.push_back(make_pair(first, 1));
		v.push_back(make_pair(second, -1));
	}
	sort(v.begin(), v.end(), cmp);
	LL opencnt = 0;
	LL lastidx = -10E9-1;
	LL len = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == -1) {
			len += (v[i].first - lastidx);
			lastidx = v[i].first;
			opencnt--;
		}

		if (v[i].second == 1) {
			++opencnt;
		}

		if (opencnt == 0) {
			continue;
		}
		else if (opencnt == 1) {
			lastidx = v[i].first;
		}

	}

	cout << len;

	return 0;
}