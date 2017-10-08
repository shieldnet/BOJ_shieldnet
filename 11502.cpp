#include <stdio.h>
#include <math.h>

int isPrime(int);

int main() {
	int prime_num[200] = { 0, };
	int prime_idx=0;
	for (int i = 1; i < 1000 + 1; i++) {
		if (isPrime(i)) {
			prime_num[prime_idx] = i;
			prime_idx++;
		}
	}
	//168 primes [0]~[167]
	int T;
	scanf("%d", &T);
	
	while (T--) {
		int K;
		scanf("%d", &K);
		int flag = 0;
		for (int first = 0; first < 168; first++) {
			for (int second = 0; second < 168; second++) {
				for (int third = 0; third < 168; third++) {
					int sum = prime_num[first] + prime_num[second] + prime_num[third];
					if (sum == K) {
						printf("%d %d %d\n", prime_num[first], prime_num[second], prime_num[third]);
						flag = 1;
						break;
					}
				}//third
				if (flag) break;
			}//second
			if (flag) break;
		}//first
	}

}

int isPrime(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}