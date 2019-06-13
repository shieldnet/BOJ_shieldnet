#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int a=0,b=0; char x = '_';
	scanf("%d%c%d", &a, &x, &b);
	if (a < 0) {
		printf("-");
	}
	if (abs(a / 2) == 1) {}
	else {
		if (x == 'x') {
			printf("%d", abs(a / 2));
		}
		else {
			printf("%d", abs(a));
		}
	}
	if (x == 'x') {
		printf("xx");
	}
	else {
		printf("x");
	}
	if (b < 0) {
		printf("-");
	}
	else if( b>0){
		printf("+");
	}
	else {}
	if(b!=0){
		if (abs(b) == 1) {}
		else {
			printf("%dx", abs(b));
		}
	}
	printf("+W");

	return 0;

}
