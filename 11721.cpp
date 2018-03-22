#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		printf("%c", s[i]);
		cnt++;
		if (cnt % 10 == 0) puts("");
	}
	return 0;
}