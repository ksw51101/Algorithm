#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt = 0, ans;
char maze[201][201];

void start(int x, int y) {
	if (x<1 || y<1 || x>n || y>m || maze[x][y] == '0')
		return;
	if (x == n && y == m)
		ans = min(ans, cnt + 1);

	maze[x][y] = '0';
	cnt++;
	start(x + 1, y);
	start(x - 1, y);
	start(x, y + 1);
	start(x, y - 1);
	maze[x][y] = '1';
	cnt--;
}

int main() {
	cin >> n >> m;
	ans = n * m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];

	start(1, 1);

	cout << ans << '\n';

	return 0;
}