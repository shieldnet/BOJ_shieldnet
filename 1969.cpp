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
typedef long double LD;

int main(void)
{
	LL ham[50 + 1]['Z' + 1] = { 0, };
	LL n, m;
	scanf("%lld%lld", &n, &m);
	vector<string> vs;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			ham[j][s[j]]++;
		}
		vs.push_back(s);
	}
	string answer_s;
	for (int i = 0; i < m; i++) {
		char mx = 0;
		int cnt = 0;
		for (int j = 'Z'; j >= 'A'; j--) {
			if (ham[i][j] >= cnt) {
				mx = j;
				cnt = ham[i][j];
			}
		}
		printf("%c", mx);
		answer_s = answer_s + mx;
	}
	printf("\n");
	LL hamdis = 0;
	for (int i = 0; i < vs.size(); i++) {
		for (int j = 0; j < vs[i].length(); j++) {
			if (vs[i][j] != answer_s[j]) hamdis++;
		}
	}
	printf("%lld", hamdis);
	return 0;
}

