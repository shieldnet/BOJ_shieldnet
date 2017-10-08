#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
LL solve(LL, LL);
VLL histogram;

int main() {
	LL N;
	LL idx, num;
	cin >> N;
	for (idx = 0; idx < N; idx++) {
		cin >> num;
		histogram.push_back(num);
	}

	cout << solve(0, N - 1);

	return 0;
}

LL solve(LL left, LL right) {
	LL lo, hi, mid;
	LL ret = 0;
	LL height;
	if (left == right) { return histogram[left]; }

	mid = (left + right) / 2;

	ret = std::max(solve(left, mid), solve(mid + 1, right));

	lo = mid, hi = mid + 1;
	height = std::min(histogram[lo], histogram[hi]);

	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || histogram[lo - 1] < histogram[hi + 1])) {
			hi++;
			height = std::min(height, histogram[hi]);
		}
		else {
			lo--;
			height = std::min(height, histogram[lo]);
		}

		ret = max(ret, height * (hi - lo + 1));

	}

	return ret;
}