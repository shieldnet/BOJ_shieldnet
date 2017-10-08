#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int solve(int);

int mem[1000001] = { 0, };

int main() {

	memset(mem, -1, 1000001 * sizeof(int));

	int n;
	cin >> n;

	cout << solve(n);

	return 0;
}

int solve(int input) {
	int& ret = mem[input];

	if (input == 1) {
		return 0;
	}

	if (ret != -1) {
		return ret;
	}

	if (input % 3 == 0) {
		int temp = solve(input / 3) + 1;
		if (ret > temp) {
			ret = temp;
		}
	}
	if (input % 2 == 0) {
		int temp = solve(input / 2) + 1;
		if (ret > temp) {
			ret = temp;
		}
	}

	if (input %2 !=0 && input%3 != 0) {
		int temp = solve(input - 1) + 1;
		if (ret > temp) {
			ret = temp;8
		}
	}


	return ret;
	


}

