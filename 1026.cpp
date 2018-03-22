#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	vector<int> a, b;
	int n, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp); a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp); b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) res += a[i] * b[n-i-1];
	printf("%d", res);
	return 0;
}