#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	int five = 0, three = 0;
	int mx = 9876543;
	for (int i = 0; i < 1001; i++) {
		if ((n - i * 5) % 3 == 0) {
			five = i;
			three = (n - i * 5) / 3;
			break;
		}
	}
	int cnt = 0;
	while (three-cnt*5 >= 0) {
		mx = min(mx, (five + cnt * 3) + (three - cnt * 5));
		cnt++;
	}

	if (mx == 9876543) {
		cout << -1; return 0;
	}
	cout << mx;

	return 0;
}