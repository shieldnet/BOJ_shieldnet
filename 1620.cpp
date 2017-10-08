#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n, m, t1;
	char t2[25];
	map <int, string> dic1;
	map <string, int> dic2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", t2);
		dic1[i] = t2;
		dic2[t2] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%s", t2);
		if (t2[0] >= '0' && t2[0] <= '9'){
			auto out = dic1[stoi(t2)];
			printf("%s\n", dic1[stoi(t2)].c_str());
		}
		else{
			printf("%d\n", dic2[t2]);
		}
	}
}