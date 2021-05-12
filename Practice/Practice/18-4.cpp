#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int parent[100000], n;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

class planet {
public:
	int x;
	int y;
	int z;
	planet(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int main() {
	cin >> n;
	vector<planet> p;
	vector<pair<int, pair<int, int>>> arr;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		p.push_back(planet(x, y, z));
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int cost = min(abs(p[i].x - p[j].x), min(abs(p[i].y - p[j].y), abs(p[i].z - p[j].z)));
			arr.push_back({ cost, {i, j} });
		}
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		int cost = arr[i].first;
		int a = arr[i].second.first;
		int b = arr[i].second.second;
		if (findParent(a) != findParent(b)) {
			ans += cost;
			unionParent(a, b);
		}
	}
	cout << ans << '\n';

	return 0;
}