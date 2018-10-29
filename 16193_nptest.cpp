#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int getmx(vector<long long>& _v) {
	long long sum = 0;
	for (int i = 0; i < _v.size() - 1; i++){
		sum += abs(_v[i] - _v[i + 1]);
	}
	return sum;
}

int main() {
	int n; scanf("%d", &n);
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long tmp; scanf("%lld", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int mx = -1;
	do {
		if (mx <= getmx(v)) {
			for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
			printf(" = %d\n", getmx(v));
			mx = getmx(v);
		}
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}