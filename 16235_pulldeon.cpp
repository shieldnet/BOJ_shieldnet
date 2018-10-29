#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//현재 벡터 참조 오류 발생하는 상태, 컴파일 에러는 없음.

const int dx[8] = { -1,0,+1,-1,+1,-1,0,+1 };
const int dy[8] = { -1,-1,-1,0,0,+1,+1,+1 };

typedef struct _dead_ree {
	int r, c, age;
} DeadTree;

typedef struct _tree {
	int age;
	bool state;
	//True = Live;
	bool born;
	//True = newly borned
} Tree;

struct CustomCompare {
	bool operator()(const Tree& a, const Tree& b) {
		return a.age < b.age;
	}
};

typedef struct _land {
	int nour;
	multiset<Tree, CustomCompare> tree;
}Land;

int a[10][10] = { 0, };

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector< vector<Land> > v(n, vector<Land>(n, { 5 }));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			scanf("%d", &a[r][c]);
		}
	}

	for (int i = 0; i < m; i++) {
		int r, c, age; scanf("%d%d%d", &r, &c, &age);
		Tree temp; temp.age = age;
		temp.state = true;
		temp.born = false;
		v[r - 1][c - 1].tree.insert(temp);
	}

	while (k--) {
		vector<DeadTree> dead;
		//spr
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				multiset<Tree, CustomCompare> next_tree;
				for (auto iter = v[r][c].tree.begin(); iter != v[r][c].tree.end(); iter++) {
					if (v[r][c].nour < ((*iter).age)) {
						DeadTree tmp;
						tmp.age = (*iter).age;
						tmp.r = r; tmp.c = c;
						dead.push_back(tmp);
						continue;
					}
					else {
						v[r][c].nour -= (*iter).age;
						Tree ageplus = (*iter);
						ageplus.age++;
						next_tree.insert(ageplus);
					}
				}
				v[r][c].tree.clear();
				v[r][c].tree = next_tree;
				next_tree.clear();
			}
		}
		//summer
		for (int i = 0; i < dead.size(); i++) {
			v[dead[i].r][dead[i].c].nour += (dead[i].age / 2);
		}
		dead.clear();
		//fall
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				for (auto iter = v[r][c].tree.begin(); iter != v[r][c].tree.end(); iter++) {
					if ((*iter).age % 5 == 0) {
						Tree brn;
						brn.age = 1;
						brn.state = true;
						for (int i = 0; i < 8; i++) {
							if (r + dy[i] < 0 || c + dx[i] < 0) continue;
							if (r + dy[i] >= n || c + dx[i] >= n) continue;
							v[r + dy[i]][c + dx[i]].tree.insert(brn);
						}
					}
				}
			}
		}

		//winter
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				v[r][c].nour += a[r][c];
			}
		}


		//Debug
		/*
		for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
		printf(">>[%d][%d] Nourish : %d\n", r, c, v[r][c].nour);
		for (auto iter = v[r][c].tree.begin(); iter != v[r][c].tree.end(); iter++) {
		printf("    R:%d C:%d AGE:%d\n", r, c, ((*iter).age));
		}
		if (v[r][c].tree.size() == 0) {
		printf("    No Tree\n");
		}
		}
		}
		puts("\n");
		*/

	}
	int ans = 0;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			ans += v[r][c].tree.size();
		}
	}
	printf("%d", ans);
	return 0;
}