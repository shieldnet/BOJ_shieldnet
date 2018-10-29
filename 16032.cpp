#include <cstdio>
#include <vector>

using namespace std;

int main() {
	while (true) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		vector<int> v;
		int sum = 0, tmp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
			v.push_back(tmp);
		}
		int ans = 0;
		double avg = (double)sum / n;
		for (int i = 0; i < v.size(); i++) {
			if ((double)(v[i]) <= avg) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}