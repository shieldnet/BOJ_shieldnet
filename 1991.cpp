#include <iostream>
#include <cstdio>

#define LEFT 0
#define RIGHT 1

using namespace std;

char ch['A' + 26 + 1][2] = { 0, };

void preorder(char);
void inorder(char);
void postorder(char);

int main() {

	int n;
	cin >> n;
	while (n--) {
		char dest, left, right;
		scanf(" %c %c %c", &dest, &left, &right);
		if (left != '.') { ch[dest][LEFT] = left; }
		if (right != '.') { ch[dest][RIGHT] = right; }
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");
	return 0;
}

void preorder(char _c) {
	
	printf("%c", _c);
	if (ch[_c][LEFT] == NULL) {	}
	else {
		preorder(ch[_c][LEFT]);
	}
	if (ch[_c][RIGHT] == NULL) {}
	else {
		preorder(ch[_c][RIGHT]);
	}
}

void inorder(char _c) {

	if (ch[_c][LEFT] == NULL) {}
	else {
		inorder(ch[_c][LEFT]);
	}
	printf("%c", _c);
	if (ch[_c][RIGHT] == NULL) {}
	else {
		inorder(ch[_c][RIGHT]);
	}
}

void postorder(char _c) {

	if (ch[_c][LEFT] == NULL) {}
	else {
		postorder(ch[_c][LEFT]);
	}
	if (ch[_c][RIGHT] == NULL) {}
	else {
		postorder(ch[_c][RIGHT]);
	}
	printf("%c", _c);
}