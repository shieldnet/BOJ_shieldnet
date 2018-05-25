//BOJ ACM-ICPC 13328, Chung-ang University
//ATEZ
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
typedef vector< VLL > matrix;

const LL mod =  31991;

matrix operator* (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

int main(){
	LL d, t;

	cin >> d >> t;

	//matrix ans = { { 1, 0 },{ 0, 1 } };
	//matrix a = { { 1, 1 },{ 1, 0 } };

	matrix ans;
	matrix a;

	for (int i = 0; i < d; i++) {
		VLL temp;
		for (int j = 0; j < d; j++) {

			if (i == j) {
				temp.push_back(1);
			}
			else {
				temp.push_back(0);
			}
		}
		ans.push_back(temp);
	}
	
	VLL shit;
	for (int i = 0; i < d; i++) {
		shit.push_back(1);
	}
	a.push_back(shit);
	for (int i = 1; i < d; i++) {
		VLL temp;
		for (int j = 0; j < d; j++) {

			if (j == i-1){
				temp.push_back(1);
			}
			else {
				temp.push_back(0);
			}
		}
		a.push_back(temp);
	}

	while (t > 0) {
		if (t % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		t /= 2;
	}

	cout << ans[0][0];

	return 0;
}