#include <queue>
#include <iostream>
#include <vector>
#include <cstdio>
#include <functional>
#include <cmath>

using namespace std;

typedef long long LL;

auto comp = [](int a, int b) {
	if (abs(a) == abs(b)) return a > b;
	else return abs(a) > abs(b);
};

int main() {
	priority_queue< LL, vector<LL>, decltype(comp)> min_heap(comp);

	int n;
	cin >> n;

	while (n--) {
		LL query = 0;
		scanf("%lld", &query);

		if (query == 0) {
			if (min_heap.empty()) {
				printf("0\n");
			}
			else {
				printf("%lld\n", min_heap.top());
				min_heap.pop();
			}
		}
		else {
			min_heap.push(query);
		}
	}




	return 0;
}