#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (col >= row) { printf("*"); }
			else { printf(" "); }
		}
		printf("\n");
	}

	return 0;
}