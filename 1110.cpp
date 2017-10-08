#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, ans = 0;
	int k = -1;
	cin >> n;
	int origin = n;
	while (true) {
		ans++;
		int temp = ((n % 10) * 10) + (((n % 10) + (n / 10)) % 10);
		if (temp == origin) { break; }
		else {
			n = temp;
		}
	}
	cout << ans;

	return 0;
}