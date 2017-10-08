#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n, m;

	scanf("%d%d", &n, &m);
	vector<int> a(n);
	vector<int> b(m);
	vector<int> res(n + m);

	for (int i = 0; i<n; ++i)scanf("%d", &a[i]);
	for (int i = 0; i<m; ++i)scanf("%d", &b[i]);

	merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());

	for (int i = 0; i<n + m; ++i)printf("%d ", res[i]);

}