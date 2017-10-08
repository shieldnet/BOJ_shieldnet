#include <cstdio>
int arr[10010] = { 0, };

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (arr[i]--) {
			printf("%d\n", i);
		}
	}

	return 0;
}