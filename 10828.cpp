#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;
typedef long long LL;

stack<LL> s;

int main() {

	LL N;
	scanf("%lld", &N);
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str[0] == 'p' && str[1] == 'u') {
			LL num;
			scanf("%lld", &num);
			s.push(num);
		}
		else if (str[0] == 't') {
			if (s.empty()) {
				printf("-1\n");
			}
			else {
				printf("%lld\n", s.top());
			}
		}
		else if (str[0] == 'e') {
			if (s.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if(str[0] == 's'){
			printf("%d\n", s.size());
		}
		else {
			if (s.empty()) {
				printf("-1\n");
			}
			else {
				LL sss = s.top();
				s.pop();
				printf("%lld\n", sss );
				
			}
		}
		
	}

	return 0;
}

