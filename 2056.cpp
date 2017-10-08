#include <iostream>
#include <string>
#include <stack>
using namespace std;

char a[31];
int check[31];
int point[31];
int i, j;
int main() {

	for (cin.getline(a, sizeof(char) * 31); a[i]; i++) {
		if (a[i] == '(' || a[i] == '[') {
			check[j] = a[i] == '(' ? ')' : ']';
			j++;
		}

		if (a[i] == ')' || a[i] == ']') {
			j--;
			if (j<0 || check[j] != a[i]) {
				point[0] = 0;
				break;
			}
			point[j] += (check[j] == ')' ? 2 : 3)*(point[j + 1] ? point[j + 1] : 1);
			point[j + 1] = 0;
		}

	}
	printf("%d", point[0]);
}

class stk {
	stk() {
		//empty
	}

	stack<char> s;


};