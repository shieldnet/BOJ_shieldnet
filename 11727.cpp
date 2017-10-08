#include <iostream>

using namespace std;

typedef long long LL;

LL arr[1001] = { 0, };

int main() {
	LL n;
	cin >> n;
	
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i < 1001; i++) {
		arr[i] = arr[i - 1] + 2 * arr[i - 2];
		arr[i] %= 10007;
	}

	cout << arr[n];

}