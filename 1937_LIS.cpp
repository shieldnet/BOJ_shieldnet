#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <time.h>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;

struct BAMBOO {
	LL val;
	LL x;
	LL y;
};

vector<BAMBOO> list;

bool isThereAround(BAMBOO, BAMBOO);
bool cmp_BAMBOO(BAMBOO, BAMBOO);
int binsearch(vector<int>&, int, int, int);
int lis(vector<BAMBOO>&);

int main() {

	clock_t st, fin;

	LL n;
	cin >> n;
	LL cnt = 0;
	for (LL i = 0; i < n; i++) {
		for (LL j = 0; j < n; j++) {
			BAMBOO temp;
			scanf("%lld", &temp.val);
			temp.x = j;
			temp.y = i;
			list.push_back(temp);
		}
	}


	st = clock();

	std::sort(list.begin(), list.end(), cmp_BAMBOO);

	cout << lis(list) << endl;

	fin = clock();
	cout << (LL)fin - st;
	return 0;
}

bool cmp_BAMBOO(BAMBOO a, BAMBOO b) {
	return a.val < b.val;
}

bool isThereAround(BAMBOO a, BAMBOO b) {
	if ((abs(a.x - b.x) == 1) && (abs(a.y - b.y) == 0)) {
		return true;
	}
	if ((abs(a.y - b.y) == 0) && (abs(a.y - b.y) == 1)) {
		return true;
	}
	
	return false;
}

int binsearch(vector<int> &v, int l, int r, int key) {
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int lis(vector<BAMBOO> &v) {
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1; // always points empty slot in tail

	tail[0] = v[0].val;
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i].val < tail[0])
			// new smallest value
			tail[0] = v[i].val;
		else if (v[i].val > tail[length - 1] && isThereAround(v[i],v[tail[length-1]])) {
			// v[i] extends largest subsequence
				tail[length++] = v[i].val;
		}
		else
			// v[i] will become end candidate of an existing subsequence or
			// Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
			// (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
			tail[binsearch(tail, -1, length - 1, v[i].val)] = v[i].val;
	}

	return length;
}
