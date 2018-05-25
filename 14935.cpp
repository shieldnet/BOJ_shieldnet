#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

LL fa(string&);
LL llfa(LL&);

int main() {
	string s;
	cin >> s;
	LL res = fa(s);

	vector<LL> v;
	v.push_back(res);
	for (int i = 0; i < 100; i++) {
		v.push_back(llfa(res));
		res = llfa(res);
	}

	for (int i = 2; i < v.size(); i++) {
		if ((v[i - 2] == v[i - 1]) && (v[i - 1] == v[i])) {
			printf("FA");
			return 0;
		}
	}
	printf("NFA");

}

LL fa(string& s) {
	if (s.length() == 0) {
		return 0;
	}
	
	return s.length()*(s[0] - '0');
}

LL llfa(LL& num) {
	string s = to_string(num);
	return fa(s);
}