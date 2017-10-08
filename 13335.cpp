#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;

LL br_wei = 0;
LL n, w, L;

typedef struct _CAR {
	LL weigh;
	LL start;
} CAR;

void rm_timeover(LL now, queue<CAR>& _br) {
	if (_br.empty()) {
		return;
	}
	else if (now - _br.front().start >= w) {
		br_wei -= _br.front().weigh;
		_br.pop();
	}
}

int main() {
	queue<CAR> q;
	queue<CAR> br;
	scanf("%lld %lld %lld", &n, &w, &L);
	//input;
	for (LL i = 0; i < n; i++) {
		LL wei;
		CAR temp;
		temp.start = 0;
		scanf("%lld", &wei);
		temp.weigh = wei;
		q.push(temp);
	}
	LL time = 0;
	while (!(q.empty() && br.empty())) {
		time++;
		rm_timeover(time, br);
		if (q.empty() || br.size() >= w) {

		}
		else if ((br_wei+q.front().weigh) <= L) {
			q.front().start = time;
			br.push(q.front());
			br_wei += q.front().weigh;
			q.pop();
		}
	}

	cout << time;

	return 0;

}