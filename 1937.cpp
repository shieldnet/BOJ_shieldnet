#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	LL n;
	cin >> n;

	cout << ((((n+1)*(n+2)/2)*3) - (2*(n+1))) % 45678;

}