#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, start, finish, cnt = 0;
vector<pair<int, int>> term;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> finish;
		term.push_back(make_pair(start, finish));
	}
	sort(term.begin(), term.end(), compare);

	finish = term[0].second;
	cnt++;
	for (int i = 1; i < n; i++)
		if (finish <= term[i].first) {
			finish = term[i].second;
			cnt++;
		}


	cout << cnt << '\n';
	return 0;
}