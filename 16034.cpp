#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long int LL;
typedef unsigned long long int ULL;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


LL S, S_2;

void func() {

	S_2 = 2 * S;

	LL left = 1, right = sqrt(S_2), mid = (left + right) / 2;
	LL maximum;

	while (left <= right) {
		if (mid*(mid + 1) <= S_2) {

			maximum = mid;
			left = mid + 1;

		}
		else {

			right = mid - 1;
		}
		mid = (left + right) / 2;
	}

	for (LL n = maximum; n >= 1; n--) {
		if ((S_2 - n*(n - 1)) % (2 * n) == 0) {

			printf("%lld %lld\n", (S_2 - n*(n - 1)) / (2 * n), n);
			return;
		}
	}
}

int main() {

	while (true) {
		scanf("%lld", &S);
		if (S == 0)break;

		func();
	}

	return 0;
}