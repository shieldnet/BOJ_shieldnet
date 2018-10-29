#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
LL solve(LL, LL, VLL&);

int main() {
	LL N;
	LL idx, num;
	while (true){
		scanf("%lld", &N);
		if (N == 0) {
			break;
		}
		VLL histogram(N, 0);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &histogram[i]);
		}

		printf("%lld\n",solve(0, N - 1,histogram));
	}
	return 0;
}

LL solve(LL left, LL right, VLL& histogram) {
	LL lo, hi, mid;
	LL ret = 0;
	LL height;
	if (left == right) { return histogram[left]; }

	mid = (left + right) / 2;

	ret = std::max(solve(left, mid, histogram), solve(mid + 1, right, histogram));

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