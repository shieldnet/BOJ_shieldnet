#include <iostream>
#include <deque>

using namespace std;
typedef long long LL;

void move(LL);
LL h, m, s;

int main() {
	cin >> h >> m >> s;

	LL tc;
	cin >> tc;
	while (tc--) {
		LL query, c;
		cin >> query;
		if (query == 1) {
			cin >> c;
			move(c);
		}
		else if (query == 2) {
			cin >> c;
			move(-c);
		}
		else if (query == 3) {
			cout << h << ' ' << m << ' ' << s << endl;

		}
		else {
			//empty
		}
	}


	return 0;
}

void move(LL c) {

	if (c < 0) {
		while (c < 0) {
			c += 86400;
		}
	}


	
	m += c / 60;
	s += c % 60;
	if (s >= 60) {
		m++;
		s = s % 60;
	}

	h += m/60;
	m = m% 60;

	h = h % 24;
	return;
}
