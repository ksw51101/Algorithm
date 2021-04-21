#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<string, int> type;
int n, score;
string name;
vector<type> vec;

bool compare(type a, type b) {
	return a.second <= b.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		vec.push_back(make_pair(name, score));
	}

	sort(vec.begin(), vec.end(), compare);
	
	for (int i = 0; i < n; i++)
		cout << vec[i].first << ' ';

	return 0;
}