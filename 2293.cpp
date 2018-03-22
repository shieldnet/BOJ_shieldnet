#include <iostream>

using namespace std;

typedef long long LL;
LL N, K;

LL method[10001];

int main(){
	cin >> N >> K;

	method[0] = 1;
	for (int i = 0; i < N; i++) {
		int coin;
		cin >> coin;

		for (int j = coin; j <= K; ++j)
		{
			method[j] += method[j - coin];
		}
	}

	cout << method[K];
	return 0;
}