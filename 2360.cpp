#include <iostream>

using namespace std;

typedef long long LL;

int arr[128][128] = { 0, };

int getBlueSquare(int, int, int);
int getWhiteSquare(int, int, int);

int main() {

	int l = 0;
	cin >> l;

	for (int r = 0; r < l; r++) {
		for (int c = 0; c < l; c++) {
			cin >> arr[r][c];
		}
	}

	cout << getWhiteSquare(0, 0, l) << endl << getBlueSquare(0, 0, l);

	return 0;
}

int getBlueSquare(int startY, int startX, int len) {
	int ret = 0;

	if (len == 1) {
		if (arr[startY][startX] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool judge = true;

	for (int row = startY; row < startY + len; row++) {
		for (int col = startX; col < startX + len; col++) {
			if (arr[row][col] == 0) {
				judge = false;
				break;
			}
		}
	}

	if (judge) {
		return 1;
	}

	else {
		ret += getBlueSquare(startY, startX, len/2);
		ret += getBlueSquare(startY+len/2, startX, len / 2);
		ret += getBlueSquare(startY, startX+ len / 2, len / 2);
		ret += getBlueSquare(startY+ len / 2, startX+ len / 2, len / 2);
	}

	return ret;
}

int getWhiteSquare(int startY, int startX, int len) {
	int ret = 0;

	if (len == 1) {
		if (arr[startY][startX] == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	bool judge = true;

	for (int row = startY; row < startY + len; row++) {
		for (int col = startX; col < startX + len; col++) {
			if (arr[row][col] == 1) {
				judge = false;
				break;
			}
		}
	}

	if (judge) {
		return 1;
	}

	else {
		ret += getWhiteSquare(startY, startX, len / 2);
		ret += getWhiteSquare(startY + len / 2, startX, len / 2);
		ret += getWhiteSquare(startY, startX + len / 2, len / 2);
		ret += getWhiteSquare(startY + len / 2, startX + len / 2, len / 2);
	}

	return ret;
}