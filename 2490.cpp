#include <iostream>

using namespace std;
int main() {
	int zero = 0, num;
	int T = 3;

	while (T--) {

		for (int cnt = 0; cnt<4; cnt++) {
			cin >> num;
			(num == 0 ? zero++ : 1);
		}

		switch (zero) {
		case 1:cout << "A" << endl;
			break;
		case 2:cout << "B" << endl;
			break;
		case 3: cout << "C" << endl;
			break;
		case 4:cout << "D" << endl;
			break;
		case 0:cout << "E" << endl;
			break;
		}
		zero = 0;
	}
}