#include <stdio.h>

int main() {

	long long arr[10001] = { 0 };
	long long n, sum = 0;

	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (arr[j] > arr[k]) {
				sum += arr[j] - arr[k];
			}
			else {
				sum += arr[k] - arr[j];
			}
		}
	}


	printf("%lld", sum);


	return 0;
}