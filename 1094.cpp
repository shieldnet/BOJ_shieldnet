#include <iostream>
#include <vector>

using namespace std;
//2진수 문제

int main() {
	vector<int> v;
	int n;
	cin >> n;
	while (n != 0) {
		v.push_back(n % 2);
		n /= 2;
	}
	int ans = 0;
	for (auto i = v.begin(); i != v.end(); i++) {
		if (*i == 1) ans++;
	}
	cout << ans;
}