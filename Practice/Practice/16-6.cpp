#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int start(string a, string b) {
	int n = a.size();
	int m = b.size();
	vector<vector<int>> vec(n, vector<int>(m));
	
	for (int i = 0; i < n; i++)
		vec[i][0] = i;
	for (int i = 0; i < m; i++)
		vec[0][i] = i;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i] == b[j])
				vec[i][j] = vec[i - 1][j - 1];
			else
				vec[i][j] = min(vec[i - 1][j - 1], min(vec[i - 1][j], vec[i][j - 1])) + 1;
		}
	}
	return vec[n - 1][m - 1];
}

int main() {
	string a, b;
	cin >> a >> b;          

	cout << start(a, b);
	return 0;
}