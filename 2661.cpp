#include <iostream>
#include <string>

using namespace std;

int n;
string s = "";
bool e = false;

void back(char c, int cnt) {

	if (n == cnt - 1) {
		cout << s;
		e = true;
		return;
	}

	s += c;
	int i, size = cnt / 2;

	for (i = 1; i <= size; i++) {
		string a = s.substr(cnt - i, i);
		string b = s.substr(cnt - i * 2, i);
		if (a == b) {
			s.erase(cnt - 1);
			return;
		}
	}

	for (i = 1; i <= 3; i++) {
		if (e == false) {
			back(i + '0', cnt + 1);
		}
	}
	s.erase(cnt - 1);
}

int main() {

	cin >> n;
	for (int i = 1; i <= 3; i++) {
		back(i + '0', 1);
	}
}