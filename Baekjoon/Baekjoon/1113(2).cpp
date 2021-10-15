#include <iostream>
using namespace std;

int n, m, ans;
char arr[50][50];
bool visited[50][50];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool DFS(int level, int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if (visited[x][y])
		return true;
	visited[x][y] = true;

	if (arr[x][y] - '0' >= level)
		return true;

	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		if (DFS(level, x + dx[dir], y + dy[dir]))
			cnt++;
	}
	if (cnt == 4)
		return true;
	else
		return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int level = 2; level < 10; level++) {
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				fill(&visited[0][0], &visited[n - 1][m], false);
				if (arr[i][j] - '0' < level && DFS(level, i, j))
					ans++;
			}
		}

	}
	cout << ans << '\n';

	return 0;
}