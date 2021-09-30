#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, dp[50][50]; // dp[x][y] : (x,y) 위치에 동전이 왔을 때 움직인 횟수의 최대값
char board[50][50];
bool visited[50][50]; // 사이클이 발생했는지 확인하기 위한 방문여부(true : 방문o, false : 방문x)
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

// 더 이상 동전이 움직일 수 없을 때까지 재귀호출하는 함수
void DFS(int x, int y, int move) {
	int num = board[x][y] - '0'; // 현재 위치의 발판 숫자

	if (visited[x][y]) { // 방문했다면 사이클이 발생했으므로 ans값 -1로 변경
		ans = -1;
		return;
	}
	if (dp[x][y] > move) // 현재 발판까지의 횟수가 이미 저장된 최대값보다 작으면 확인할 필요가 없으므로 종료
		return;

	visited[x][y] = true; // 방문처리
	for (int dir = 0; dir < 4; dir++) {
		if (ans == -1) // 사이클이 발생했으면 그대로 종료
			return;
		int nx = x + dx[dir] * num; // 새로운 x값
		int ny = y + dy[dir] * num; // 새로운 y값

		if (board[nx][ny] == 'H' || nx < 0 || ny < 0 || nx >= n || ny >= m) { // (nx,ny)로 움직였을 때 더 움직일 수 없다면
			dp[x][y] = max(dp[x][y], move + 1); // (x,y)에서 움직일 수 있는 최대값 갱신
			ans = max(ans, move + 1); // ans 갱신
			continue;
		}
		DFS(nx, ny, move + 1); // 새로운 위치에서 재귀호출
	}
	visited[x][y] = false; // 방문처리 되돌림
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