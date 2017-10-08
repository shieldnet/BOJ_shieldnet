#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int isVisited[1001] = {0, };
vector<int> v;
vector<int> visit;
int judge = 0;
void dfs(int);

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		v.push_back(0);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}
		
		//pre
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == i) {
				isVisited[i] = 100005;
				ans++;
			}
		}

	}


	return 0;
}

void dfs(int vertex) {
	isVisited[vertex] = judge;
	if (!isVisited[v[vertex]]) {
		visit.push_back(v[vertex]);
		dfs(v[vertex]);
	}
}