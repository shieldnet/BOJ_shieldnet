#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
typedef long long LL;

typedef priority_queue<LL, vector<LL>, greater<LL> > min_heap;
typedef priority_queue<LL> max_heap;

int main() {

	int n;
	cin >> n;
	min_heap a;
	while (n--) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (a.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << a.top() << endl;
				a.pop();
			}
		}
		else {
			a.push(temp);
		}
		

	}

}