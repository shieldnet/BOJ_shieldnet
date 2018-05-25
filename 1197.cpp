#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long lld;
typedef long double Ld;
typedef pair<lld, lld> pll;

#define sci(n) scanf("%lld", &(n))

typedef pair<lld, pll> edge;

void link(vector<int> &, int, int);
int find(vector<int> &, int);

int main(void)
{
	lld n, e;
	sci(n), sci(e);
	vector<edge> edges;
	for (int i = 0; i < e; ++i)
	{
		lld v, w, c;
		sci(v), sci(w), sci(c);
		edges.push_back(edge(c, pll(v, w)));
	}

	vector<int> uf(n + 1);
	for (int i = 0; i < n + 1; ++i)    uf[i] = i;
	sort(edges.begin(), edges.end());
	lld cost = 0;
	for (int i = 0; i < e; ++i)
	{
		lld v = edges[i].second.first, w = edges[i].second.second;
		if (find(uf, v) != find(uf, w))
		{
			link(uf, v, w);
			cost += edges[i].first;
		}
	}

	cout << cost << endl;

	return 0;
}

void link(vector<int> &uf, int x, int y)
{
	uf[find(uf, x)] = find(uf, y);
}

int find(vector<int> &uf, int x)
{
	if (uf[x] == x)    return x;
	return uf[x] = find(uf, uf[x]);
}
