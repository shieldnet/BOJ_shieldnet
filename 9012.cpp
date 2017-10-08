#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;
LL wellMatchedAndCount(const string&);

int main() {
	LL n;
	cin >> n;
	string str;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		printf("Case #%d\n", i);
		if (str.length() == 0) {
			cout << 0 << endl;
			continue;
		}
		else {
			cout << wellMatchedAndCount(str);
		}
	}
	return 0;

}

LL wellMatchedAndCount(const string& fomula) {
	const string op("({["), cl(")}]");
	stack<char> openStack;
	LL idx;
	LL mxSize = -1;
	LL nowSize = 0;
	for (idx = 0; idx<fomula.size(); idx++) {
		if (op.find(fomula[idx]) != -1) {
			openStack.push(fomula[idx]);
			nowSize = openStack.size();
			mxSize = max(nowSize, mxSize);
		}
		else {
			nowSize = 0;
			if (openStack.empty()) {
				return 0;
			}
			if (op.find(openStack.top()) != cl.find(fomula[idx])) {
				return 0;
			}
			openStack.pop();
		}
	}
	return mxSize;
}