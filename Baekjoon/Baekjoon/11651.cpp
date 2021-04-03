#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int n, x, y, begin, end;
	vector<pair<int, int>> vec;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';

	return 0;
}