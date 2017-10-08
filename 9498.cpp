#include <iostream>

using namespace std;

int main() {

	int s;
	cin >> s;
	if (s <= 100 && s >= 90) cout << 'A';
	else if (s <= 89 && s >= 80) cout << 'B';
	else if (s <= 79 && s >= 70) cout << 'C';
	else if (s <= 69 && s >= 60) cout << 'D';
	else cout << 'F';
		
	return 0;
}