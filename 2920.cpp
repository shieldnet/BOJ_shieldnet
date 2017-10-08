#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string v;
	for (int i = 0; i < 8; i++){
		int temp; scanf("%1d", &temp); v += to_string(temp);
	}
	if (strcmp(v.c_str(), "12345678") == 0) { cout << "ascending"; }
	else if ((strcmp(v.c_str(), "87654321") == 0)) { cout << "descending"; }
	else { cout << "mixed"; }
	
	return 0;
}
