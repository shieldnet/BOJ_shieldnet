#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> collect_sum;
vector<int> v;
bool include[25] = { false, };
int n;

int sumofelement(vector<int>& v) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (include[i]) sum += v[i];
	}
	return sum;

}

bool isEmpty() {
	for (int i = 0; i < 21; i++) {
		if (include[i]) {
			return false;
		}
	}
	return true;
}

void powerset(int k) {
	if (k == v.size()) {
		if (isEmpty()) {
		}
		else {
			collect_sum.push_back(sumofelement(v));
		}
		return;
	}
	include[k] = false;
	powerset(k + 1);
	include[k] = true;
	powerset(k + 1);
}

int main() {
	
	int S = 0;
	scanf("%d%d", &n,&S);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	powerset(0);
	int ans = 0;
	sort(collect_sum.begin(), collect_sum.end());
	for (int i = 0; i < collect_sum.size(); i++) {
		if (collect_sum[i] == S) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}