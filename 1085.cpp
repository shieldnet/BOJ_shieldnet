#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << std::min(min(x,abs(x - w)), min(y,abs(y - h)));
}