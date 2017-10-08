#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
	vector<LL> v;
	LL n; scanf("%lld", &n);
	for (int i = 0; i < n; i++) { LL temp; scanf("%lld", &temp); v.push_back(temp); }
	sort(v.begin(), v.end());
	LL sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (v.size()-i)*v[i];
	}
	cout << sum;
	return 0;
}