#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first)
		return a.first < b.first;
	else
		return a.second.first < b.second.first;
}

int main() {
	int n, age, begin, end;
	string name;
	vector<pair<int, pair<int, string>>> vec;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		vec.push_back(make_pair(i, make_pair(age, name)));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].second.first << ' ' << vec[i].second.second << '\n';

	return 0;
}