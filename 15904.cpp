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
		if (arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && s.at(i) == 'U') // U�� �������;� üũ.
			arr[0]++;
		else if (arr[0] > 0 && arr[2] == 0 && arr[3] == 0 && s.at(i) == 'C') // U�� �տ� ���Դٰ� Ȯ�δ�� üũ.
			arr[1]++;
		else if (arr[0] > 0 && arr[1] > 0 && arr[3] == 0 && s.at(i) == 'P') // U,P�� �տ� ���;� üũ.
			arr[2]++;
		else if (arr[1] > 0 && arr[2] > 0 && s.at(i) == 'C') // U,C,P�� ������� ���;� üũ.
			arr[3]++;
	}
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0 && arr[3] > 0)
		cout << "I love UCPC" << endl;
	else
		cout << "I hate UCPC" << endl;
}