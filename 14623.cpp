#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;


int main() {
	LL arr[32] = { 0, };
	arr[0] = 1; arr[1] = 2;
	for (int i = 1; i < 31; i++) {
		arr[i] = arr[i - 1] * 2;
	}

	string a, b;

	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	LL _a = 0, _b = 0;

	for (int i = 0; i < a.length(); i++) {
		_a += (a[i] - '0')*arr[i];
	}
	for (int i = 0; i < b.length(); i++) {
		_b += (b[i] - '0')*arr[i];
	}

	LL ret = _a*_b;

	vector<LL> v;

	while (ret != 0) {
		v.push_back(ret % 2);
		ret /= 2;
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	
	return 0;
}