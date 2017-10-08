#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	vector<int> v;
	scanf("%d", &n);
	for (auto i = 0; i != n; i++) {
		int tmp; scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int q = -1;
	for (auto i = 0; i != 10000 + 1; i++) {
		int over = 0;
		int nonover = 0;

		for (auto j = v.begin(); j != v.end(); j++) {
			if (*j >= i) over++;
			else if (*j < i) {
				nonover++;

			}
		}
		if (over >= i && nonover <= (n - i)) {
			q = max(q,i);
		}
	}

	cout << q;

	return 0;
}