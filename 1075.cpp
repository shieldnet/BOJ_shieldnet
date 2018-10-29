#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
typedef long long LL;
using namespace std;
int main() {
	LL n, k;
	cin >> n >> k;
	n = (n / 100) * 100;
	for (int i = 0; i < 100; i++) {
		if ((n+i)%k == 0) {
			string s = to_string(n+i);
			cout << s.substr(s.length() - 2, s.length());
			
			break;
		}
	}

	return 0;
}