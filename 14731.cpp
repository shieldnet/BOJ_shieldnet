#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef long long LL;

//10의 9승 + 7로 나눈 나머지를 구해야하므로.
const LL MOD = 1000000007;

/*
fast_power은 x^y승을 구할때, x를 y번 곱하지 않고, y를 2진수로 나타낸 다음
한자리씩 밀면서 더합니다. 예를 들어서 2의 5승 2^101(2)이므로

base = 2, power = 101(2)
처음에 result = 1 * 2^1

그다음 base = base*base해서 base = 4가 되었습니다.
base = 4, power = 10(2) 한칸 shifting
 result = 1 * 2^1 (그대로) power 맨 뒷자리가 0이니까

 그다음 base = base*base 해서 base가 16이 되었습니다.
 base = 16, power = 1(2) 한칸 shifting
 result = 1 * 2^1 * 2^4 = 32.

 완료.
*/
long long fast_power(long long base, long long power) {
	long long result = 1;
	while (power > 0) {

		if (power % 2 == 1) {
			result = (result*base) % MOD;
		}
		base = (base%MOD * base%MOD) % MOD;
		power = power / 2;
	}
	return result;
}

int main() {
	//항의 개수
	LL n;
	scanf("%lld", &n);
	//f'(2)
	LL f2 = 0;
	
	//N번 loop
	while (n--) {
		//계수와 차수를 받아서
		LL c = 0, k = 0;
		scanf("%lld %lld", &c, &k);
		if (k == 0 || c == 0) continue;
		//미분 -> 변수에 2를 대입해서 구함.
		f2 += (( c % MOD * k % MOD) % MOD) * (fast_power(2, k - 1) % MOD) % MOD;
		//나머지 처리해주고
		f2 %= MOD;
	}
	//최종적으로 한번 더 나머지 처리
	f2 %= MOD;

	printf("%lld", f2);
	return 0;
}