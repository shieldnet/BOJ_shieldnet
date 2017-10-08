#include <iostream>

using namespace std;

typedef long long LL;

LL MOD;

LL fastpow(LL, LL);

int main() {
	LL A, B;

	cin >> A >> B >> MOD;

	cout << fastpow(A, B) % MOD;

	return 0;
}

LL fastpow(LL base, LL power) {

	if (power == 0) {
		return 1;
	}
	if (power == 1) {
		return base;
	}

	LL result = fastpow(base, power / 2);
	result %= MOD;
	result *= result;
	result %= MOD;

	if (power % 2 == 1) {
		result *= base;
		result %= MOD;
	}
	result %= MOD;
	return result;
}