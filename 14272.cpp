#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> h;

int solve(int left, int right) {
	if (left == right) return h[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));

	//ªÁ¿Ãø°
	int lo = mid;
	int hi = mid + 1;
	int height = min(h[lo], h[hi]);

	ret = max(ret, 2 * height);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		h.push_back(temp);
	}

	cout << solve(0, n - 1);

}