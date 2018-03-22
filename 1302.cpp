#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;

int main() {
	map<string, LL> mp;
	LL n;
	scanf("%lld", &n);
	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
	}
	LL mx = -1;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if ((*iter).second >= mx) {
			mx = (*iter).second;
		}
	}
	vector<string> vs;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if ((*iter).second == mx) {
			vs.push_back((*iter).first);
		}
	}
	sort(vs.begin(), vs.end());

	cout << vs[0];
	return 0;
}