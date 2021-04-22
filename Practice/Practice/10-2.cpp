#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> p;
int n, m, root[100001];
vector<p> vec;


int check_root(int a) {
	if (root[a] == a)
		return a;
	else
		return root[a] = check_root(root[a]);
}

void make_union(int a, int b) {
	a = check_root(a);
	b = check_root(b);
	if (a > b)
		root[a] = b;
	else
		root[b] = a;
}

int main() {
	cin >> n >> m;
	 
	for (int i = 0; i <= 100000; i++)
		root[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ c, {a, b} });
	}
	sort(vec.begin(), vec.end());

	int cost = 0, max_cost = 0;
	for (int i = 0; i < m; i++) {
		if (check_root(vec[i].second.second) != check_root(vec[i].second.first)) {
			make_union(vec[i].second.second, vec[i].second.first);
			cost += vec[i].first;
			max_cost = vec[i].first;
		}
	}
	cost -= max_cost;

	cout << cost << '\n';

	return 0;
}