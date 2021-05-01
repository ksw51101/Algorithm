#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m, map[51][51], ans = 100000;
vector<pair<int, int>> house, chicken;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i, j });
			else if (map[i][j] == 2)
				chicken.push_back({ i, j });
		}
	vector<bool> binary(chicken.size());
	fill(binary.end() - m, binary.end(), true);

	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = n * n;
			for (int j = 0; j < chicken.size(); j++) {
				if (binary[j] == true) {
					dist = min(dist, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
				}
			}
			sum += dist;
		}
		ans = min(ans, sum);
	} while (next_permutation(binary.begin(), binary.end()));
	cout << ans << '\n';

	return 0;
}