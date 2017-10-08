#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL findLivingDay(LL, LL);

LL cache[501][501] = { 0, };
LL map[501][501] = { 0, };
LL dy[4] = { 0, 0, 1, -1 };
LL dx[4] = { 1, -1,0,  0 };

int main() {
	LL n;

	for (LL i = 0; i < 501; i++)	{
		for (LL j = 0; j < 501; j++){
			cache[i][j] = -1;
		}
	}

	cin >> n;

	for (LL i = 0; i < n; i++)	{
		for (LL j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}

	LL ret = 0;

	for (LL y = 0; y < n; y++){
		for (LL x = 0; x < n; x++){
			ret = max(ret, findLivingDay(y, x));
		}
	}

	cout << ret << endl;

	return 0;
}

LL findLivingDay(LL y, LL x)
{
	LL &ret = cache[y][x];

	if (ret != -1) return ret;

		ret = 1;

	for (LL i = 0; i<4; i++){
		LL ry = y + dy[i];
		LL rx = x + dx[i];

		if (map[y][x] < map[ry][rx]){
			ret = max(ret, findLivingDay(ry, rx) + 1);
		}
	}

	return ret;
}