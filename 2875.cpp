#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, M, K;
	cin >> N >> M >> K;

	int mxteam = 987654321;

	mxteam = std::min(N / 2, M);
	N -= mxteam * 2;
	M -= mxteam;

	while (N + M < K) {
		mxteam--;
		N += 2;
		M += 1;
	}
	printf("%d", mxteam);

	return 0;
}