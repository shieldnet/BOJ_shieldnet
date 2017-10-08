#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int main() {
	queue<int> q;
	int t;
	cin >> t;

	while (t--) {
		string str;

		cin >> str;
		//push
		if (str[0] = 'p' && str[1] == 'u') {
			int num;
			scanf("%d", &num);
			q.push(num);
		}
		//pop
		else if (str[0] = 'p' && str[1] == 'o') {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		//size
		else if (str[0] == 's') {
			printf("%d\n", q.size());
		}
		//empty
		else if (str[0] == 'e') {
			if (q.empty()) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}
		//front
		else if (str[0] == 'f') {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
	return 0;
}