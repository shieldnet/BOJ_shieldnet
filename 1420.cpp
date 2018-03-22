#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int roff[4] = { -1, 1, 0, 0 };
const int coff[4] = { 0, 0, -1, 1 };


const int INF = 1000000000;

struct Maxflow {
	int n;
	struct Edge {
		int next;
		int inv;
		int cap;
	};
	vector<vector<Edge> > graph;
	Maxflow(int n) {
		this->n = n;
		graph.assign(n, vector<Edge>());
	}
	void add_edge(int u, int v, int c, int rev_c) {
		Edge foward, backward;
		foward.next = v;
		foward.cap = c;
		foward.inv = graph[v].size();
		backward.next = u;
		backward.cap = rev_c;
		backward.inv = graph[u].size();
		graph[u].push_back(foward);
		graph[v].push_back(backward);
	}

	int bfs(int source, int sink) {
		vector<bool> visited(n, false);
		vector<pair<int, int > > parent(n, pair<int, int>(-1, -1));
		visited[source] = true;
		queue<int> que;
		que.push(source);
		while (!que.empty()) {
			int here = que.front();
			que.pop();
			for (int i = 0; i < graph[here].size(); i++) {
				int next = graph[here][i].next;
				if (!visited[next] && graph[here][i].cap) {
					visited[next] = true;
					parent[next].first = here;
					parent[next].second = i;
					que.push(next);
				}
			}
		}
		if (parent[sink].first == -1) return 0;

		int minflow = INF;

		int p = sink;
		while (parent[p].first != -1) {
			minflow = min(minflow, graph[parent[p].first][parent[p].second].cap);
			p = parent[p].first;
		}
		p = sink;
		while (parent[p].first != -1) {
			Edge& e = graph[parent[p].first][parent[p].second];
			e.cap -= minflow;
			graph[e.next][e.inv].cap += minflow;
			p = parent[p].first;
		}
		return minflow;
	}
	int flow(int source, int sink) {
		int flow = 0;
		int ret = 0;
		while (flow = bfs(source, sink)) {
			ret += flow;
		}
		return ret;
	}
};

struct Edge {
	int u, v, c, f;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int c1) : u(u1), v(v1), c(c1), f(0) {}
	int oppo(int s) {
		return (s == u ? v : u);
	}
	int spare(int s) {
		if (s == u) return c - f;
		return f;
	}
	void addFlow(int s, int nf) {
		if (s == u) f += nf;
		else f -= nf;
	}
};

int main() {
	int N, M, S, E;
	vector<Edge*> adj[20000];
	char map[100][100];
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			map[i][j] = getchar();
			if (map[i][j] == 'K') S = 2 * (i*M + j) + 1;
			else if (map[i][j] == 'H') E = 2 * (i*M + j);
		}
		getchar();
	}
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (map[i][j] == '#') continue;
			if (map[i][j] == 'H') {
				for (int d = 0; d<4; d++) {
					int ni = i + roff[d], nj = j + coff[d];
					if (ni >= 0 && ni<N && nj >= 0 && nj<M && map[ni][nj] == 'K') {
						puts("-1");
						return 0;
					}
				}
			}

			int c1 = 2 * (i*M + j), c2 = c1 + 1;
			Edge *edge = new Edge(c1, c2, 1);
			adj[c1].push_back(edge);
			adj[c2].push_back(edge);

			for (int d = 0; d<4; d++) {
				int ni = i + roff[d], nj = j + coff[d];
				if (ni<0 || ni >= N || nj<0 || nj >= M || map[ni][nj] == '#') continue;
				int n1 = 2 * (ni*M + nj), n2 = n1 + 1;
				edge = new Edge(c2, n1, INF);
				adj[c2].push_back(edge);
				adj[n1].push_back(edge);
			}
		}
	}

	int result = 0;
	while (true) {
		int prev[20000];
		fill(prev, prev + 20000, -1);
		Edge *edge[20000] = { nullptr };
		queue<int> Q;
		Q.push(S);

		while (!Q.empty() && prev[E] == -1) {
			int curr = Q.front();
			Q.pop();
			for (Edge *e : adj[curr]) {
				int next = e->oppo(curr);
				if (e->spare(curr) && prev[next] == -1) {
					prev[next] = curr;
					edge[next] = e;
					Q.push(next);
				}
			}
		}
		if (prev[E] == -1) break;

		for (int i = E; i != S; i = prev[i])
			edge[i]->addFlow(edge[i]->oppo(i), 1);
		result++;
	}
	printf("%d\n", result);
}