#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;

typedef struct _dot {
	_dot() {};
	_dot(int x, int y) {
		this->_x = x;
		this->_y = y;
	}
	int _x;
	int _y;

	bool operator < (const _dot &v) const {
		if (_y == v._y) {
			return _x < v._x;
		}
		else {
			return _y < v._y;
		}
	}

} dot ;

auto cmp_x = [](dot& a, dot& b) {
	return (a._x < b._x);
};

auto cmp_y = [](dot& a, dot& b) {
	return (a._y < b._y);
};

LL distance(dot& a, dot& b) {
	LL x = a._x, xx = b._x, y = a._y, yy = b._y;
	return (((x - xx)*(x - xx)) + ((y - yy)*(y - yy)));
}

int main() {
	vector<dot> v;
	set<dot> s;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		dot temp; int _x, _y;
		scanf("%d%d", &_x, &_y);
		v.push_back(dot(_x,_y));
	}
	sort(v.begin(), v.end(), cmp_x);
	s = { v[0],v[1] };
	LL max_dist = distance(v[0], v[1]);

	//일단 set을 사용하고, idx 2~n까지 전체탐색 하면서
	//처음 잰 거리보다 작은 dot들을 다 cutting 하는거임 그리고 일단
	//다 Bianry tree에 넣어
	LL start = 0;
	for (int idx = 2; idx < v.size(); idx++) {
		dot cur = v[idx];
		//Cutting
		while(start<idx) {

			dot p = v[start];
			LL x = cur._x - p._x;
			if (x*x > max_dist) {
				s.erase(p);
				start++;
			}
			else {
				break;
			}

		}

		LL dist = max_dist + 1;
		auto lo = dot(-10e5, cur._y-dist);
		auto hi = dot(10e5, cur._y +dist);
		auto lb = s.lower_bound(lo);
		auto hb = s.upper_bound(hi);

		for (auto iter = lb; iter != hb; iter++) {
			
			dot cmp_dot;
			cmp_dot._x = (*iter)._x;
			cmp_dot._y = (*iter)._y;
			LL d = distance(cur, cmp_dot);
			if (d < max_dist) {
				max_dist = d;
			}
		}
		s.insert(cur);
	}

	cout << max_dist;


	return 0;
}