
#define _CRT_SECURE_NO_WARNIGNS 
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <cstring>
#include <sstream>  
#include <string>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> pll;

int stage[501] = { 0, };

typedef struct _fail{
	int stage_num;
	double p;
} fail;

bool compare (fail a, fail b) {
	if (a.p==b.p){
		return a.stage_num < b.stage_num;
	}
	else {
		return a.p >= b.p;
	}
};

vector<int> solution(int N, vector<int> stages) {
	int partialsum[501] = { 0, };
	int challenge[501] = { 0, };
	
	for (int i = 0; i < stages.size(); i++) {
		challenge[stages[i]]++;
	}

	for (int i = 1; i <= N+1; i++) {
		partialsum[i] = partialsum[i - 1] + challenge[i];
	}

	if (challenge[N + 1] == 0) {
		partialsum[N + 1] = partialsum[N];
	}
	
	vector<fail> ans;
	for (int i = 1; i <= N; i++) {
		fail f = { 0,0};
		f.stage_num = i;
		f.p = (double)challenge[i]/(double)((double)partialsum[N + 1] - partialsum[i - 1]);
		ans.push_back(f);
	}

	sort(ans.begin(), ans.end(), compare);


	vector<int> answer;
	for (int i = 0; i < ans.size(); i++) {
		answer.push_back(ans[i].stage_num);
	}


	return answer;
}

int main(void)
{
	int N = 5;
	vector<int> answer;
	vector<int> v = { 5, 5, 5,5,5,5,5,5};
	answer = solution(N, v);

	for (auto iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}

