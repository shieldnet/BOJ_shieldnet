#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

int main() {

	LL a, b;
	string c;

	cin >> a >> b >> c;

	if ((c[c.length()-1]-'0') & 1) {
		cout << (a ^ b);
	}
	else {
		cout << ((a ^ b) ^ b);
	}
	

	return 0;
}