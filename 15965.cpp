#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;
#define MAX 10000000

int sieve[MAX] = { false, };

int main() {
	for (int i = 0; i < MAX; i++) sieve[i] = i;
	int k; scanf("%d", &k);
	sieve[1] = 0;
	sieve[0] = 0;
	for (int i = 2; i <= MAX; i++) {
		if (sieve[i] == 0) continue;
		for (int j = i + i; j < MAX; j += i)	sieve[j] = 0;
	}


	int pos = 0,ret=-1;
	for (int i = 0; i < MAX; i++) {
		if (sieve[i] != 0) { pos++; }

		if (pos == k) {
			ret =sieve[i];
			break;
		}
		
	}
	printf("%d", ret);


	return 0;
}