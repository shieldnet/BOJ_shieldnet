#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;

VLL fibo;

int main() {

	fibo.push_back(0);
	fibo.push_back(1);
	LL n;
	cin >> n;
	for (int i = 2; i < 1000; i++) {
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}

	cout << fibo[n];

	return 0;
}