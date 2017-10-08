#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef long long LL;

int main() {

	queue<LL> q;

	LL N;
	scanf("%lld", &N);
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str[0] == 'p' && str[1] == 'u') {
			LL num;
			cin >> num;
			q.push(num);
		}
		else if (str[0] == 'f') {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (str[0] == 'b') {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
		else if (str[0] == 's') {
			cout << q.size() << endl;
		}
		else if (str[0] == 'e') {
			if (q.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {

				cout << q.front() << endl;
				q.pop();
			}
		}

	}


	return 0;
}