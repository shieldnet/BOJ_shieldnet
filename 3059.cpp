#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		bool b[26] = { false, };
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			b[str[i] - 'A'] = true;
		}
		for (int i = 0; i < 26; i++) {
			if (!b[i]) ans += 'A' + i;
			//printf(">> %c", i + 'A');
		}
		printf("%d\n", ans);
	}

	return 0;
}