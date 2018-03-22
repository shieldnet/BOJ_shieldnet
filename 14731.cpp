#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef long long LL;

//10�� 9�� + 7�� ���� �������� ���ؾ��ϹǷ�.
const LL MOD = 1000000007;

/*
fast_power�� x^y���� ���Ҷ�, x�� y�� ������ �ʰ�, y�� 2������ ��Ÿ�� ����
���ڸ��� �и鼭 ���մϴ�. ���� �� 2�� 5�� 2^101(2)�̹Ƿ�

base = 2, power = 101(2)
ó���� result = 1 * 2^1

�״��� base = base*base�ؼ� base = 4�� �Ǿ����ϴ�.
base = 4, power = 10(2) ��ĭ shifting
 result = 1 * 2^1 (�״��) power �� ���ڸ��� 0�̴ϱ�

 �״��� base = base*base �ؼ� base�� 16�� �Ǿ����ϴ�.
 base = 16, power = 1(2) ��ĭ shifting
 result = 1 * 2^1 * 2^4 = 32.

 �Ϸ�.
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
	//���� ����
	LL n;
	scanf("%lld", &n);
	//f'(2)
	LL f2 = 0;
	
	//N�� loop
	while (n--) {
		//����� ������ �޾Ƽ�
		LL c = 0, k = 0;
		scanf("%lld %lld", &c, &k);
		if (k == 0 || c == 0) continue;
		//�̺� -> ������ 2�� �����ؼ� ����.
		f2 += (( c % MOD * k % MOD) % MOD) * (fast_power(2, k - 1) % MOD) % MOD;
		//������ ó�����ְ�
		f2 %= MOD;
	}
	//���������� �ѹ� �� ������ ó��
	f2 %= MOD;

	printf("%lld", f2);
	return 0;
}