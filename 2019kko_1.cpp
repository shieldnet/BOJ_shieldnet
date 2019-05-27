
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

#define ENTER 1
#define LEAVE 0

typedef struct _query {
	int uid;
	int state;
} query;


vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

int get_uid(string& _s) {
	size_t pos = _s.find("uid");
	string ret = _s.substr(pos + 3);
	return stoi(ret);
}

vector<string> solution(vector<string> record) {
	map<int, string> info;
	vector<string> answer;
	vector<query> q;

	info.clear();
	answer.clear();
	q.clear();

	for (auto iter = record.begin(); iter != record.end(); iter++) {
		vector<string> splited = split(*iter, ' ');

		query ip_query;
		int uid = get_uid(splited[1]);
		if (splited.size() == 3) {
			if (splited[0] == "Enter") {
				ip_query.state = ENTER;
				ip_query.uid = uid;
				info[uid] = splited[2];
				q.push_back(ip_query);
			}
			else if (splited[0] == "Change") {
				info[uid] = splited[2];
			}
		}
		else {
			if (splited[0] == "Leave") {
				ip_query.state = LEAVE;
				ip_query.uid = uid;
				q.push_back(ip_query);
			}
		}
	}
	for (int pos = 0; pos < q.size(); pos++) {
		string add_str;
		if (q[pos].state == ENTER) {
			add_str = info[q[pos].uid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		}
		else if(q[pos].state == LEAVE){
			add_str = info[q[pos].uid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}
		else {
			exit(1);
		}
		answer.push_back(add_str);
	}

	return answer;
}

int main(void)
{
	vector<string> input = {"Enter uid1234 Muzi", "Enter uid0 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 ProdoaaaaAaaAaaaAAA23","Change uid4567 Ryan","Change uid4567 Ryan22" };
	vector<string> answer;
	answer = solution(input);

	for (auto iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}

