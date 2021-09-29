#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, dp[50][50]; // dp : ���� ��ġ���� �̵��Ͽ��� �� �ִ� �̵�Ƚ�� ����
char board[50][50];
bool visited[50][50]; // ����Ŭ �Ǻ��� �湮���� Ȯ��
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int DFS(int x, int y) {
	if (board[x][y] == 'H' || x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	int num = board[x][y] - '0'; // ���� ������ �ִ� ���� ����

	if (visited[x][y]) { // �湮�� ���� ������ ����Ŭ�� �߻��� ���̹Ƿ� -1 ���
		cout << -1 << '\n';
		exit(0);
	}

	int &cache = dp[x][y];
	if (cache != -1)
		return cache;

	cache = 0;
	visited[x][y] = true; // ���� ��ġ �湮ó��

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * num; // x�� �̵�
		int ny = y + dy[i] * num; // y�� �̵�

		cache = max(cache, DFS(nx, ny) + 1);
	}
	visited[x][y] = false; // ���� ��ġ �湮���

	return cache;
}

int main() {
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	cout << DFS(0, 0) << '\n';

	return 0;
}