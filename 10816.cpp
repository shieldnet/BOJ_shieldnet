#include <iostream>
#include <cstdio>

using namespace std;

int arr[20000001] = { 0, };

int main() {

	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp + 10000000]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		temp += 10000000;
		printf("%d ", arr[temp]);
	}
	return 0;
}