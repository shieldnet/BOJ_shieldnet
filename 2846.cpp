#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n, temp = -1, mx = -1;
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		v.push_back(temp);
	}
	int first = -1, last = -1;
	first = v[0];
	if (v.size() == 1) {
		cout << 0;
		return 0;
	}
	last = v[0];
	int last_idx = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > last) { last = v[i]; }
		else {
			ans = max(last - v[last_idx], ans);
			last_idx = i;
			last = v[i];
		}
	}
	ans = max(last - v[last_idx], ans);
	cout << ans;

	
	return 0;
}