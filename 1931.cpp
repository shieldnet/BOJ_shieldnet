#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct _TIME{
	int st;
	int fin;
} TIME;

bool cmp(TIME a, TIME b) {
	if (a.fin < b.fin) {
		return true;
	}
	else if (a.fin == b.fin) {
		return (a.st < b.st);
	}
	return false;
}

int main() {
	vector<TIME> v;

	int n;
	cin >> n;
	TIME tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &tmp.st, &tmp.fin);
		v.push_back(tmp);
	}
	int ans = 0;
	sort(v.begin(), v.end(), cmp);
	int last = 0;
	for (auto i = v.begin(); i != v.end(); i++) {
		if ((*i).st >= last) {
			ans++;
			last = (*i).fin;
		}
	}
	cout << ans;

	return 0;
}