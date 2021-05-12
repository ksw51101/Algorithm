#include <iostream>
#include <vector>
using namespace std;

int n, m, parent[501], route[501][501];

int find_parents(int a) {
	if (a = parent[a])
		return a;
	return parent[a] = find_parents(parent[a]);
}

void make_union(int a, int b) {
	a = find_parents(a);
	b = find_parents(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> n >> m;
	vector<int> target;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> route[i][j];
			if (route[i][j] == 1)
				make_union(i, j);
		}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		target.push_back(temp);
	}
	bool ans = true;
	for (int i = 0; i < m - 1; i++)
		if (find_parents(target[i]) != find_parents(target[i + 1]))
			ans = false;
	if (ans == true)
		cout << "YES" << "\n";
	else
		cout << "NO" << '\n';

	return 0;
}