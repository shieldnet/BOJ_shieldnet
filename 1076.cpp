#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	vector<string> v(10);
	map<string, pair<long long, long long> > mul;
	
	v = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	for (int i = 0; i < v.size(); i++) {
		mul[v[i]].first = (long long)pow(10, i);
		mul[v[i]].second = i;
	}
	mul[v[0]].first = 1;
	long long ret = 0;
	string a, b, c;
	cin >> a >> b >> c;
	ret = (mul[a].second * 10 + mul[b].second)*mul[c].first;
	cout << ret;
	return 0;

}