#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, dp[50][50]; // dp[x][y] : (x,y) ��ġ�� ������ ���� �� ������ Ƚ���� �ִ밪
char board[50][50];
bool visited[50][50]; // ����Ŭ�� �߻��ߴ��� Ȯ���ϱ� ���� �湮����(true : �湮o, false : �湮x)
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

// �� �̻� ������ ������ �� ���� ������ ���ȣ���ϴ� �Լ�
void DFS(int x, int y, int move) {
	int num = board[x][y] - '0'; // ���� ��ġ�� ���� ����

	if (visited[x][y]) { // �湮�ߴٸ� ����Ŭ�� �߻������Ƿ� ans�� -1�� ����
		ans = -1;
		return;
	}
	if (dp[x][y] > move) // ���� ���Ǳ����� Ƚ���� �̹� ����� �ִ밪���� ������ Ȯ���� �ʿ䰡 �����Ƿ� ����
		return;

	visited[x][y] = true; // �湮ó��
	for (int dir = 0; dir < 4; dir++) {
		if (ans == -1) // ����Ŭ�� �߻������� �״�� ����
			return;
		int nx = x + dx[dir] * num; // ���ο� x��
		int ny = y + dy[dir] * num; // ���ο� y��

		if (board[nx][ny] == 'H' || nx < 0 || ny < 0 || nx >= n || ny >= m) { // (nx,ny)�� �������� �� �� ������ �� ���ٸ�
			dp[x][y] = max(dp[x][y], move + 1); // (x,y)���� ������ �� �ִ� �ִ밪 ����
			ans = max(ans, move + 1); // ans ����
			continue;
		}
		DFS(nx, ny, move + 1); // ���ο� ��ġ���� ���ȣ��
	}
	visited[x][y] = false; // �湮ó�� �ǵ���
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	DFS(0, 0, 0);

	cout << ans << '\n';

	return 0;
}