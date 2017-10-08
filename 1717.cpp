#include <iostream>
#include <cstdio>

using namespace std;

int set[1000010] = { 0, };

int findParent(int);
void isUnion(int, int);

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		set[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int command;
		int f, t;
		scanf("%d", &command);
		if (command == 0) {
			scanf("%d%d", &f, &t);
			isUnion(f, t);
		}
		else {
			scanf("%d%d", &f, &t);
			if (findParent(f) == findParent(t)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}


	return 0;
}

void isUnion(int v1, int v2) {
	v1 = findParent(v1);
	v2 = findParent(v2);
	if (v1 != v2) {
		set[v2] = v1;
	}
}

int findParent(int num) {
	if (set[num] == num) {
		return num;
	}
	else {
		set[num] = findParent(set[num]);
		return set[num];
	}
}

