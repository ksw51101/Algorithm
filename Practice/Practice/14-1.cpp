#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

class score {
public:
	string name;
	int k;
	int e;
	int m;
	score(string name, int k, int e, int m) {
		this->name = name;
		this->k = k;
		this->e = e;
		this->m = m;
	}
};

bool compare(score a, score b) {
	if (a.k == b.k) {
		if (a.e == b.e) {
			if (a.m == b.m) {
				return a.name < b.name;
			}
			return a.m > b.m;
		}
		return a.e < b.e;
	}
	return a.k > b.k;
}

int main() {
	cin >> n;
	vector<score> people;

	for (int i = 0; i < n; i++) {
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		score person = score(name, k, e, m);
		people.push_back(person);
	}

	sort(people.begin(), people.end(), compare);
	for (int i = 0; i < people.size(); i++)
		cout << people[i].name << '\n';

	return 0;
}