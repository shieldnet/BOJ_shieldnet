#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;


const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll fact(int n) {
	if (n == 0 || n == 1) return 1;
	return n*fact(n - 1);
}
int N;
ll cache[12][102][102][102];
ll factorial[101] = { 0, };

ll solve(int level, int R, int G, int B) {
	if (R<0 || G<0 || B<0) return 0;
	if (level == N + 1) return 1;
	ll& cache = cache[level][R][G][B];
	if (cache != -1) return cache;
	ll ret = 0;

	ret += solve(level + 1, R - level, G, B);
	ret += solve(level + 1, R, G - level, B);
	ret += solve(level + 1, R, G, B - level);

	if (level % 2 == 0) {
		ret += solve(level + 1, factorial[R - level / 2], factorial[G - level / 2], B)*(fact(level) / (ll)pow(level / 2, 2));
		ret += solve(level + 1, R - level / 2, G, B - level / 2)*(fact(level) / (ll)pow(level / 2, 2));
		ret += solve(level + 1, R, G - level / 2, B - level / 2)*(fact(level) / (ll)pow(level / 2, 2));
	}

	if (level % 3 == 0) 
		ret += solve(level + 1, R - level / 3, G - level / 3, B - level / 3)*(fact(level) / (ll)pow(level / 3, 3));


	return cache = ret;
}

int main() {
	factorial[0] = 1;
	for (int i = 1; i < 101; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	memset(cache, -1, sizeof(cache));
	int R, G, B;
	inp4(N, R, G, B);
	printf("%lld", solve(1, R, G, B));
	return 0;
}