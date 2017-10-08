#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	vector<int> v;
	v.push_back(1);
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i+v[v.size()-1]);
		}
	}
	int a, b;
	scanf("%d%d", &a, &b);
	cout << v[b] - v[a-1];


	return 0;
}