#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<int> v;
		for (int i = 0; i < 16; i++) {
			int temp;
			scanf("%1d", &temp);
			v.push_back(temp);
		}
		reverse(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (i %2==1) {
				int tem = v[i] * 2;
				if (tem >= 10) {
					int a, b;
					a = tem / 10;
					b = tem % 10;
					v[i] = a + b;
				}
				else {
					v[i] = tem;
				}
			}
			else {

			}
		}
		int sum = 0;
		for (int i = 0; i < 16; i++) {
			sum += v[i];
		}
		if (sum % 10 == 0) {
			printf("T\n");
		}
		else {
			printf("F\n");
		}
	}
}