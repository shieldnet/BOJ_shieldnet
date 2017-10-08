#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	vector<int> v2(v);

	int ans_right = 0;
	for (int i = v2.size()-1; i >=1; i--) {
		if (v2[i] <= v2[i - 1]) {
			
			ans_right += abs(v2[i] - v2[i - 1]) + 1;
			v2[i - 1] = v2[i] - 1;
		}
		else {
			//empty
		}
	}

	printf("%d", ans_right);


	return 0;
}