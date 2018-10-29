#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct _grp {
	string name;
	vector<string> member;
} grp;

int main() {
	int n, m;
	vector<grp> v;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		grp temp;
		int num;
		cin >> temp.name;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string s;
			cin >> s;
			temp.member.push_back(s);
		}
		sort(temp.member.begin(), temp.member.end());
		v.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		string nm;
		cin >> nm;
		int pb;
		cin >> pb;

		if (pb == 0) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].name == nm) {
					for (int j = 0; j < v[i].member.size(); j++) {
						cout << v[i].member[j] << "\n";
					}
				}
			}
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[i].member.size(); j++) {
					if (nm == v[i].member[j]) {
						cout << v[i].name << "\n";
					}
				}
			}
		}
	}
	

	return 0;
}