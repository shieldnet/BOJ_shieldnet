#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool isVisited[1001] = { false };
vector<int> v;
vector<int> visit;

void dfs(int);

int main() {

	int t;
	cin >> t;
	while (t--) {
		v.push_back(0);
		int cycle = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}

		for (int i = 1; i < v.size(); i++) {
			if (!isVisited[i]) {
				cycle++;
				dfs(i);
			}
		}

		v.clear();
		visit.clear();
		for (int i = 0; i < 1001; i++) {
			isVisited[i] = false;
		}
		cout << cycle << endl;
	}


	return 0;
}

void dfs(int vertex) {
	isVisited[vertex] = true;
	if (!isVisited[v[vertex]]) {
		visit.push_back(v[vertex]);
		dfs(v[vertex]);
	}
}