#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int arr[4] = { 0, };
	for (int i = 0; i < s.length(); i++)
	{
		if (arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && s.at(i) == 'U') // U가 먼저나와야 체크.
			arr[0]++;
		else if (arr[0] > 0 && arr[2] == 0 && arr[3] == 0 && s.at(i) == 'C') // U가 앞에 나왔다고 확인대야 체크.
			arr[1]++;
		else if (arr[0] > 0 && arr[1] > 0 && arr[3] == 0 && s.at(i) == 'P') // U,P가 앞에 나와야 체크.
			arr[2]++;
		else if (arr[1] > 0 && arr[2] > 0 && s.at(i) == 'C') // U,C,P가 순서대로 나와야 체크.
			arr[3]++;
	}
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0 && arr[3] > 0)
		cout << "I love UCPC" << endl;
	else
		cout << "I hate UCPC" << endl;
}