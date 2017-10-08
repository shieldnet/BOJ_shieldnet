#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;

typedef struct _mem {
	string name;
	int year;
	int order;
} mem ;

auto cmp = [](mem& a, mem& b) {
	if (a.year < b.year) {
		return true;
	}
	else if( a.year>b.year) {
		return false;
	}
	else {
		return (a.order < b.order);
	}
};

int main() {
	LL n;
	vector<mem> v;

	scanf("%lld", &n);
	
	for (int i = 0; i < n; i++) {
		mem temp;
		char nm[101] = { 0, };
		int y = 0;
		scanf(" %d %s", &y, &nm);
		temp.name = string(nm);
		temp.year = y;
		temp.order = i;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		printf("%d %s\n", v[i].year, v[i].name.c_str());
	}


	return 0;
}