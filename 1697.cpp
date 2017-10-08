#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

typedef long long LL;
bool visit[100001] = { false, };
int nth[100001] = { 0, };

int main() {
	queue<int> q;
	int n, k;
	for (int i = 0; i <= 100000; i++) {
		nth[i] = -1;
	}
	cin >> n >> k;
	int cnt = 0;
	q.push(n);
	while (true) {
		cnt++;
		int tmp = q.front();
		visit[tmp] = true;
		nth[n] = 1;
		//printf("%d ", tmp);
		if (tmp == k) {
			cout << nth[tmp]-1;
			break;
		}
		
		if (tmp - 1 < 0 || visit[tmp-1]) {
		}
		else { 
			q.push(tmp - 1); 
			visit[tmp - 1] = true;
			if (nth[tmp - 1] == -1) {
				nth[tmp - 1] = nth[tmp] + 1;
			}
		}

		if (tmp + 1 > 100000 || visit[tmp+1]) {
		}
		else { 
			q.push(tmp + 1); 
			visit[tmp + 1] = true;
			if (nth[tmp+1] == -1) {
				nth[tmp + 1] = nth[tmp] + 1;
			}
		}

		if (tmp*2 > 100000 || visit[tmp*2]) {
		}
		else { 
			q.push(tmp *2); 
			visit[tmp*2] = true;
			if (nth[tmp*2] == -1) {
				nth[tmp*2] = nth[tmp] + 1;
			}
		}

		q.pop();
	}
	

	return 0;
}

