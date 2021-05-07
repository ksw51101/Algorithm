#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000
int n, m;

int main() {
	cin >> n >> m;
	vector<vector<int>> minimum(n, vector<int>(n));
	fill(minimum.begin(), minimum.end(), vector<int>(n, INF));
	for (int i = 0; i < n; i++)
		minimum[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		from--;
		to--;
		minimum[from][to] = min(minimum[from][to], cost);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				minimum[j][k] = min(minimum[j][k], minimum[j][i] + minimum[i][k]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (minimum[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << minimum[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}