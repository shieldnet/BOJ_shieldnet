#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cursor = 0;
		for (int i = 0; i < s.length(); i++) {
			if (cursor <= 0) cursor = 0;
			if (cursor > s.length()) cursor = s.length();
			
			switch (s[cursor]) {
			case '<':
				cursor--;
				break;
			case '>':
				cursor++;
				break;
			case '-':
				cursor--;
				break;
			default:
				//v풀다가잠
			}

			if (cursor <= 0) cursor = 0;
			if (cursor > s.length()) cursor = s.length();
		}
	}


	return 0;
}