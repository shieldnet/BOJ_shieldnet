#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char str[1000020] = { 0, };
int alpha[1000] = { 0, };

int main() {

	scanf("%s", str);
	for (int i = 0; i < 1000001; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}

	for (int i = 0; i < 1000001;i++) {
		alpha[str[i]]++;
	}
	int maxal = -1;
	int mxidx = -1;
	for (int i = 1; i < 1000; i++) {
		if (maxal <= alpha[i]) {
			mxidx = i;
			maxal = alpha[i];
		}
	}
	
	int dupcnt = 0;

	for (int i = 1; i < 1000; i++) {
		if (maxal == alpha[i])dupcnt++;
	}
	if (dupcnt >= 2) {
		printf("?");
		return 0;
	}

	if (mxidx >= 'a' && mxidx <= 'z') {
		mxidx -= 32;
	}

	printf("%c", mxidx);

	return 0;
}