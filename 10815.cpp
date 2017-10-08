#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());

	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		printf("%d ", binary_search(v.begin(), v.end(), k));
	}



	return 0;
}