#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

int n, m;

int main() {
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(n));
	vector<bool> check(n, false);
	fill(vec.begin(), vec.end(), vector<int>(n, INF));
	for (int i = 0; i < n; i++)
		vec[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a - 1][b - 1] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				vec[j][k] = min(vec[j][i] + vec[i][k], vec[j][k]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (vec[i][j] == INF && vec[j][i] == INF)
				check[i] = check[j] = true;

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (check[i] == true)
			cnt++;
	cout << n - cnt << '\n';

	return 0;
}