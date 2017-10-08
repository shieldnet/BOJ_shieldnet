#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
typedef vector<LL> VLL;
typedef string S;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int cache[100][100] = { 0, };
vector< vector<int> > input;
vector<int> danji;
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0, 0,1,-1 };
int mx_r;
int mx_c;

int fill(int r, int c, int color) {
	if (cache[r][c] != -1) {
		return 0;
	}
	if (r < 0 || c <0 || r >= mx_r || c >= mx_c) {
		return 0;
	}
	int mxsize = 0;

	if (input[r][c] == 0) {
		cache[r][c] = 0;
		return 0;
	}

	cache[r][c] = 999;
	mxsize++;

	for (int iter = 0; iter < 4; iter++) {
		if (r + dy[iter] < 0 || c + dx[iter] <0 || r + dy[iter] >= mx_r || c + dx[iter] >= mx_c) {
			continue;
		}
		if ((input[r + dy[iter]][c + dx[iter]]) == color) {
			mxsize += fill(r + dy[iter], c + dx[iter], color);
		}
	}

	return mxsize;
}


vector<int> solution(int m, int n, vector< vector<int> > picture) {
	input = picture;
	mx_r = m;
	mx_c = n;
	memset(cache, -1, sizeof(cache));
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0 || cache[i][j] != -1) {
				cache[i][j] = 99;
				continue;
			}
			else {
				number_of_area++;
				danji.push_back(fill(i, j, picture[i][j]));
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}


int main() {
	int m, n;
	cin >> m;
	n = m;

	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%1d", &t);
			temp.push_back(t);
		}
		input.push_back(temp);
	}


	auto ans = solution(m, n, input);
	sort(danji.begin(), danji.end());
	cout << ans[0] << endl;

	for (int i = 0; i < danji.size(); i++) {
		cout << danji[i] << endl;
	}
	return 0;
}