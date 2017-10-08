#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
int main() {
	LL n;
	vector<LL> v;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		LL temp; scanf("%lld", &temp); v.push_back(temp);
	}
	LL sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			sum += abs(v[i] - v[j]);
		}
	}
	printf("%lld", sum);
	return 0;
}