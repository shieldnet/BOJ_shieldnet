#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;
int main() {

	//Ȧ���� �߰��� �ִ� ���� �ϳ� �Ǿ����� ������
	//¦���� ���� �˰������� ����


	int n; scanf("%d", &n);
	vector<long long> front,back, all;
	vector<long long> kotae;
	for (int i = 0; i < n; i++) {
		long long temp; scanf("%lld", &temp);
		all.push_back(temp);
	}
	// 4 1 5 2 6 3 
	sort(all.begin(), all.end());
	int odd_temp = -1000000;
	if (n & 1) {
		odd_temp = all[all.size() / 2];
		all.erase(all.begin()+(n/2));
	}
	int pos = 0;
	for (; pos < all.size() / 2; pos++) front.push_back(all[pos]);
	for (; pos < all.size(); pos++) back.push_back(all[pos]);

	if (n&1) {
		kotae.push_back(odd_temp);
	}
	for (int i = 0; i < front.size(); i++) {
		kotae.push_back(back[i]);
		kotae.push_back(front[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += abs(kotae[i] - kotae[i + 1]);
	}
	kotae.clear();

	reverse(front.begin(), front.end());
	reverse(back.begin(), back.end());

	if (n&1) {
		kotae.push_back(odd_temp);
	}
	for (int i = 0; i < front.size();i++) {
		kotae.push_back(front[i]);
		kotae.push_back(back[i]);
	}


	//���⿡ ���� 4 5 6 1 2 3 ������ ¦¦�A ������ ��Ǯ�� ������ ������ ����~~

	long long ans2 = 0;
	for (int i = 0; i < n-1; i++) {
		ans2 += abs(kotae[i] - kotae[i + 1]);
	}
	printf("%lld", max(ans,ans2));
	return 0;
}