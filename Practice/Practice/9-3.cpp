#include <iostream>
#include <algorithm>
#define inf 9999999
using namespace std;

int n, m, x, k, link[101][101];

int main() {
	cin >> n >> m;

	fill(&link[0][0], &link[101][102], inf);

	for (int i = 1; i <= n; i++)
		link[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		link[a][b] = 1;
		link[b][a] = 1;
	}
	cin >> x >> k;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				link[j][k] = min(link[j][k], link[j][i] + link[i][k]);
	
	int ans = link[1][k] + link[k][x];
	if (ans >= inf)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}