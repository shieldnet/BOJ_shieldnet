#define _CRT_SECURE_NO_WARNIGNS 
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long LL;


struct FenwickTree2D {
	vector<vector<LL> > tree;
	FenwickTree2D(LL r, LL c) : tree(r, vector<LL>(c)) {}

	void add(int r, int c, LL val) {
		for (int i = r; i<tree.size(); i |= i + 1)
			for (int j = c; j<tree[0].size(); j |= j + 1)
				tree[i][j] += val;
	}

	//sum [(0,0),(r,c)]
	LL sum(int r, int c) {
		LL ret = 0;
		for (LL i = r; i >= 0; i = (i&(i + 1)) - 1)
			for (LL j = c; j >= 0; j = (j&(j + 1)) - 1)
				ret += tree[i][j];
		return ret;
	}

	//sum [(r1,c1) , (r2,c2)]
	LL sum(int r1, int c1, int r2, int c2) {
		return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
	}
};

int main(void)
{
	LL n, m, q;
	scanf("%lld%lld%lld", &n, &m, &q);

	struct FenwickTree2D ft = FenwickTree2D(5001, 5001);

	while (q--) {
		LL command = 0;
		scanf("%lld", &command);
		if (command == 1) {
			LL x1, y1, x2, y2, d;
			scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &d);
			ft.add(x1, y1, d);
			ft.add(x2 + 1, y1, -d);
			ft.add(x1, y2 + 1, -d);
			ft.add(x2 + 1, y2 + 1, d);
		}
		else {
			LL x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", ft.sum(x,y));
		}
	}
	return 0;
}

