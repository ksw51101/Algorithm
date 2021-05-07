#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void start(int n, int m, vector<vector<int>> &vec, vector<vector<int>> &maximum) {
	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				maximum[i][j] = max(maximum[i][j - 1], maximum[i + 1][j - 1]) + vec[i][j];
			}
			else if (i == n - 1) {
				maximum[i][j] = max(maximum[i][j - 1], maximum[i - 1][j - 1]) + vec[i][j];
			}
			else {
				maximum[i][j]= max(max(maximum[i][j - 1], maximum[i - 1][j - 1]), maximum[i+1][j-1]) + vec[i][j];
			}

		}
	}
}

int main() {
	int T, m, n, ans;
	cin >> T;

	for (int i = 0; i < T; i++) {
		ans = 0;
		cin >> n >> m;
		vector<vector<int>> vec(n, vector<int>(m));
		for(int j=0;j<n;j++)
			for (int k = 0; k < m; k++) {
				int gold;
				cin >> gold;
				vec[j][k] = gold;
			}
		vector<vector<int>> maximum(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			maximum[i][0] = vec[i][0];
		start(n, m, vec, maximum);

		for (int i = 0; i < n; i++) {
			ans = max(maximum[i][m - 1], ans);
		}
		cout << ans << '\n';
	}
	return 0;
}