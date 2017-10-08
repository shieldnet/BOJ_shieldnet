#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		double x1, y1, r1, x2, y2, r2, d;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = sqrt(pow(x1 - x2, 2) + pow(x2 - y2, 2));

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1";
		}
		else if (r1 + r2 - d < 0) {
			cout << "2";
		}
		else if (r1 + r2 - d > 0) {
			cout << "0";
		}
		else {
			cout << "1";
		}

		cout << endl;
	}

}