#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, dp[50][50]; // dp : 현재 위치에서 이동하였을 때 최대 이동횟수 저장
char board[50][50];
bool visited[50][50]; // 사이클 판별용 방문여부 확인
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int DFS(int x, int y) {
	if (board[x][y] == 'H' || x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	int num = board[x][y] - '0'; // 현재 동전이 있는 곳의 숫자

	if (visited[x][y]) { // 방문한 적이 있으면 사이클이 발생한 것이므로 -1 출력
		cout << -1 << '\n';
		exit(0);
	}

	int &cache = dp[x][y];
	if (cache != -1)
		return cache;

	cache = 0;
	visited[x][y] = true; // 현재 위치 방문처리

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * num; // x값 이동
		int ny = y + dy[i] * num; // y값 이동

		cache = max(cache, DFS(nx, ny) + 1);
	}
	visited[x][y] = false; // 현재 위치 방문취소

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