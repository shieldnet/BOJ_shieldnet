#include <iostream>
#include <string>
using namespace std;
int main() {
	char c;
	c = getchar();
	while (c + 1 != 0) {
		putchar(c);
		c = getchar();
	}
	return 0;
}