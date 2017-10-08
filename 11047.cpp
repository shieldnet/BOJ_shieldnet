#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int main() {
	vector<LL> v;
	LL n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		LL temp; cin >> temp;
		v.push_back(temp);
	}
	reverse(v.begin(), v.end());
	LL idx = 0;
	LL gesu = 0;
	while (m != 0) {
		while (true) {
			if (m >= v[idx]) {
				m -= v[idx];
				gesu++;
			}
			else {
				idx++;
				break;
			}
		}
	}
	cout << gesu;
	return 0;
}