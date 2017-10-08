#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<LL> VLL;

VLL card;
LL ans = 0;

int main() {

	LL n;
	cin >> n;
	LL max_value = -1;
	LL max_index = -1;

	LL sum = 0;
	for (LL i = 0; i < n; i++) {
		LL temp;
		cin >> temp;
		card.push_back(temp);
		max_value = max(max_value, temp);
		sum += temp;
	}

	for (LL i = 0; i < n; i++) {
		if (card[i] == max_value) {
			max_index = i;

		}
	}

	LL left_num = max_index - 1;
	LL right_num = card.size() - max_index - 1;
	
	ans += max_value*card.size() + sum - 2*max_value;


	
	cout << ans << endl;

	return 0;
}