#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

struct CustomCmp {
	bool operator()(const string& a, const string& b) {
		if (a.length() < b.length()) {
			return true;
		}
		else if (a.length() == b.length()) {
			return a < b;
		}
		else {
			return false;
		}
	}
};

int main() {
	set<string, CustomCmp> st;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		st.insert(s);
	}
	for (auto iter = st.begin(); iter != st.end(); iter++) {
		cout << (*iter) << "\n";
	}
	return 0;
}